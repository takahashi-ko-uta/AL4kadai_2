//#include "enemy.h"
//#include <stdio.h>
//#include <time.h>
//
//void Enemy::Initialize(Input* input)
//{
//	input_ = input;
//	//オブジェクトを指定
//	model_ = Model::LoadFromOBJ("enemy");
//	//3Dオブジェクトと3Dモデルを紐づける
//	object3d->SetModel(model_);
//	//オブジェクトの初期設定
//	float scale = 2.0f;
//	object3d->SetScale({ scale,scale,scale });
//}
//
//void Enemy::Update()
//{
//	Move();
//}
//
//void Enemy::Move()
//{
//	float speed = 0.1f;
//	uint16_t interval = 20;
//	srand(time(nullptr));
//	//方向を抽選
//	if (isMove == true)
//	{
//		++moveTimer;
//		if (moveTimer >= interval)
//		{
//			moveDirection = rand() % 4 + 1;//1～4を取得
//			isMove = false;
//		}
//	}
//
//	//移動
//	switch (moveDirection)
//	{
//	case 1://上
//		Position.y += speed;
//		isMove = true;
//		break;
//	case 2://下
//		Position.y -= speed;
//		isMove = true;
//		break;
//	case 3://左
//		Position.x -= speed;
//		isMove = true;
//		break;
//	case 4://右
//		Position.x += speed;
//		isMove = true;
//		break;
//	}
//	object3d->SetPosition({ Position.x, Position.y, Position.z });
//	object3d->Update();
//}
//
//void Enemy::SpriteDraw()
//{
//
//}
//
//void Enemy::ObjDraw()
//{
//	object3d->Draw();
//}