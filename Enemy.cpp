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
	object3d->SetScale({ scale,scale,scale });
	object3d->Update();
}

void Enemy::Update()
{
	Move();

	//�Ԋu�������čU������
	const uint16_t interval = 50;
	if (atttackTimer <= interval)
	{
		atttackTimer++;
		if (atttackTimer >= interval)
		{
			Attack();
			atttackTimer = 0;
		}
	}
	
	for (std::unique_ptr<EnemyBullet>& bullet : bullets_) {
		bullet->Update();
	}

	//�f�X�t���O���������e��r��
	bullets_.remove_if([](std::unique_ptr<EnemyBullet>& bullet) { return bullet->IsDead(); });
}

void Enemy::Move()
{
	float speed = 0.1f;
	uint16_t interval = 20;
	srand(time(nullptr));
	//�����𒊑I
	if(isMove == true)
	{
		++moveTimer;
		if(moveTimer >= interval)
		{
			moveDirection = rand()%4+1;//1�`4���擾
			isMove = false;
		}
	}

	//�ړ�
	switch (moveDirection)
	{
	case 1://��
		position_.y += speed;
		isMove = true;
		break; 
	case 2://��
		position_.y -= speed;
		isMove = true;
		break;
	case 3://��
		position_.x -= speed;
		isMove = true;
		break;
	case 4://�E
		position_.x += speed;
		isMove = true;
		break;
	}
	object3d->SetPosition({ position_.x, position_.y, position_.z });
	object3d->Update();
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