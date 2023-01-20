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
	//���[���h���W������ϐ�
	XMFLOAT3 worldPos;
	//���[���h�s��̕��s�ړ��������擾

	worldPos.x = position_.x;
	worldPos.y = position_.y;
	worldPos.z = position_.z;

	return worldPos;
}


void Enemy::OnCollision()
{
	isDied = true;
}