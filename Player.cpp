#include "Player.h"

void Player::Initialize(Input* input)
{
	input_ = input;
	//�I�u�W�F�N�g���w��
	model_ = Model::LoadFromOBJ("player");
	//3D�I�u�W�F�N�g��3D���f����R�Â���
	object3d->SetModel(model_);
	//�I�u�W�F�N�g�̏����ݒ�
	float scale = 2.0f;
	object3d->SetScale({ scale,scale,scale });
}

void Player::Update()
{
	Move();
}

void Player::Move()
{
	//�ړ�
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
