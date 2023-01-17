#include "enemy.h"
#include <stdio.h>
#include <time.h>

void Enemy::Initialize(Input* input)
{
	input_ = input;
	//�I�u�W�F�N�g���w��
	model_ = Model::LoadFromOBJ("enemy");
	//3D�I�u�W�F�N�g��3D���f����R�Â���
	object3d->SetModel(model_);
	//�I�u�W�F�N�g�̏����ݒ�
	float scale = 2.0f;
	position_ = { -40.0f,20.0f,0.0f };
	object3d->SetPosition({ position_.x, position_.y, position_.z });
	object3d->SetScale({ scale,scale,scale });
	object3d->Update();
}

void Enemy::Approach()
{
	if(position_.x <= 0.0f)
	{
		position_.x += 0.5f;
	}
	else 
	{
		moveNum = 1;
	}
	object3d->SetPosition({ position_.x, position_.y, position_.z });
	object3d->Update();
}

void Enemy::Shot()
{
	//�e�𐶐����A������
	std::unique_ptr<EnemyBullet> newBullet = std::make_unique<EnemyBullet>();
	newBullet->Initialize(model_, position_);

	//�e��o�^����
	bullets_.push_back(std::move(newBullet));

	moveNum = 2;
}

void Enemy::Leave()
{
	position_.x++;
	position_.y += 3;

	object3d->SetPosition({ position_.x, position_.y, position_.z });
	object3d->Update();
}

void(Enemy::* Enemy::spFuncTamle[])() = {
	&Enemy::Approach, //�ڋ�
	&Enemy::Shot,     //�ˌ�
	&Enemy::Leave	  //���E
};

void Enemy::Update()
{
	Move();

	for (std::unique_ptr<EnemyBullet>& bullet : bullets_) {
		bullet->Update();
	}

	//�f�X�t���O���������e��r��
	bullets_.remove_if([](std::unique_ptr<EnemyBullet>& bullet) { return bullet->IsDead(); });
}

void Enemy::Move()
{
	switch (moveNum)
	{
	case 0:
		(this->*spFuncTamle[0])();
		break;
	case 1:
		(this->*spFuncTamle[1])();
		break;
	case 2:
		(this->*spFuncTamle[2])();
		break;
	}
}

void Enemy::Attack()
{
	//�e�𐶐����A������
	std::unique_ptr<EnemyBullet> newBullet = std::make_unique<EnemyBullet>();
	newBullet->Initialize(model_,position_);

	//�e��o�^����
	bullets_.push_back(std::move(newBullet));
}

void Enemy::SpriteDraw()
{

}

void Enemy::ObjDraw()
{
	object3d->Draw();
	//�e�`��
	for (std::unique_ptr<EnemyBullet>& bullet : bullets_) {
		bullet->Draw();
	}
}



