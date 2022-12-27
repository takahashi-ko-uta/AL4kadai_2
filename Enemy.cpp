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
	object3d->SetScale({ scale,scale,scale });
	object3d->Update();
}

void Enemy::Update()
{
	Move();

	//間隔をあけて攻撃する
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

	//デスフラグが立った弾を排除
	bullets_.remove_if([](std::unique_ptr<EnemyBullet>& bullet) { return bullet->IsDead(); });
}

void Enemy::Move()
{
	//float speed = 0.1f;
	//uint16_t interval = 20;
	//srand(time(nullptr));
	////方向を抽選
	//if(isMove == true)
	//{
	//	++moveTimer;
	//	if(moveTimer >= interval)
	//	{
	//		moveDirection = rand()%4+1;//1～4を取得
	//		isMove = false;
	//	}
	//}

	////移動
	//switch (moveDirection)
	//{
	//case 1://上
	//	Position.y += speed;
	//	isMove = true;
	//	break; 
	//case 2://下
	//	Position.y -= speed;
	//	isMove = true;
	//	break;
	//case 3://左
	//	Position.x -= speed;
	//	isMove = true;
	//	break;
	//case 4://右
	//	Position.x += speed;
	//	isMove = true;
	//	break;
	//}
	//object3d->SetPosition({ Position.x, Position.y, Position.z });
	//object3d->Update();

	//移動
	float speed = 0.1f;
	if (input_->PushKey(DIK_UP))
	{
		position_.y += speed;
	}
	if (input_->PushKey(DIK_DOWN))
	{
		position_.y -= speed;
	}
	if (input_->PushKey(DIK_LEFT))
	{
		position_.x -= speed;
	}
	if (input_->PushKey(DIK_RIGHT))
	{
		position_.x += speed;
	}
	//position_.z = -20.0f;
	position_.z = 0.0f;
	position_.x = -20.0f;
	object3d->SetPosition({ position_.x, position_.y, position_.z });
	object3d->Update();
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