#include "enemy.h"
#include <stdio.h>
#include <time.h>

void Enemy::Initialize(Input* input)
{
	input_ = input;
	//オブジェクトを指定
	model_ = Model::LoadFromOBJ("enemy");
	//3Dオブジェクトと3Dモデルを紐づける
	object3d->SetModel(model_);
	//オブジェクトの初期設定
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
	//弾を生成し、初期化
	std::unique_ptr<EnemyBullet> newBullet = std::make_unique<EnemyBullet>();
	newBullet->Initialize(model_, position_);

	//弾を登録する
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
	&Enemy::Approach, //接近
	&Enemy::Shot,     //射撃
	&Enemy::Leave	  //離脱
};

void Enemy::Update()
{
	Move();

	for (std::unique_ptr<EnemyBullet>& bullet : bullets_) {
		bullet->Update();
	}

	//デスフラグが立った弾を排除
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
	//弾を生成し、初期化
	std::unique_ptr<EnemyBullet> newBullet = std::make_unique<EnemyBullet>();
	newBullet->Initialize(model_,position_);

	//弾を登録する
	bullets_.push_back(std::move(newBullet));
}

void Enemy::SpriteDraw()
{

}

void Enemy::ObjDraw()
{
	object3d->Draw();
	//弾描画
	for (std::unique_ptr<EnemyBullet>& bullet : bullets_) {
		bullet->Draw();
	}
}



