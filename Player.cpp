#include "Player.h"

void Player::Initialize(Input* input)
{
	input_ = input;
	//オブジェクトを指定
	model_ = Model::LoadFromOBJ("player");
	//3Dオブジェクトと3Dモデルを紐づける
	object3d->SetModel(model_);
	//オブジェクトの初期設定
	float scale = 2.0f;
	object3d->SetScale({ scale,scale,scale });
}

void Player::Update()
{
	Move();
}

void Player::Move()
{
	//移動
	float speed = 0.1f;
	if (input_->PushKey(DIK_UP))
	{
		Position.y += speed;
	}
	if (input_->PushKey(DIK_DOWN))
	{
		Position.y -= speed;
	}
	if (input_->PushKey(DIK_LEFT))
	{
		Position.x -= speed;
	}
	if (input_->PushKey(DIK_RIGHT))
	{
		Position.x += speed;
	}
	Position.z = -20.0f;
	object3d->SetPosition({ Position.x, Position.y, Position.z });
	object3d->Update();
}

void Player::SpriteDraw()
{
	
}

void Player::ObjDraw()
{
	object3d->Draw();
}
