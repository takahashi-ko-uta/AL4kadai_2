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
	object3d->Update();
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
	position_.z = -20.0f;
	//position_.z = 0.0f;
	object3d->SetPosition({ position_.x, position_.y, position_.z });
	object3d->Update();
}

void Player::SpriteDraw()
{
	
}

void Player::ObjDraw()
{
	object3d->Draw();
}

void Player::OnCollision()
{
	
}

XMFLOAT3 Player::GetPosition()
{
	//ワールド座標を入れる変数
	XMFLOAT3 worldPos;
	//ワールド行列の平行移動成分を取得

	worldPos.x = position_.x;
	worldPos.y = position_.y;
	worldPos.z = position_.z;

	return worldPos;
}
