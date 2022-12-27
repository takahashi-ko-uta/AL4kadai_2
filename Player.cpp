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
	object3d->Update();
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
	//���[���h���W������ϐ�
	XMFLOAT3 worldPos;
	//���[���h�s��̕��s�ړ��������擾

	worldPos.x = position_.x;
	worldPos.y = position_.y;
	worldPos.z = position_.z;

	return worldPos;
}
