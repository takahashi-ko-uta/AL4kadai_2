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
	//position_ = { 0,+20,0 };
	object3d->SetPosition({ position_.x,position_.y,position_.z });
	object3d->Update();
}



void Enemy::SpriteDraw()
{

}

void Enemy::ObjDraw()
{
	if(isDied == false)
	{
		object3d->Draw();
	}
}

XMFLOAT3 Enemy::GetPosition()
{
	//ワールド座標を入れる変数
	XMFLOAT3 worldPos;
	//ワールド行列の平行移動成分を取得

	worldPos.x = position_.x;
	worldPos.y = position_.y;
	worldPos.z = position_.z;

	return worldPos;
}


void Enemy::OnCollision()
{
	isDied = true;
}