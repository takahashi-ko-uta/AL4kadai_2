#include "enemy.h"
#include <stdio.h>
#include <time.h>

void Enemy::Initialize(Input* input)
{
	input_ = input;
	//�I�u�W�F�N�g���w��
	model_ = Model::LoadFromOBJ("enemy");
	//3D�I�u�W�F�N�g��3D���f����R�Â���
	object_1->SetModel(model_);
	object_2->SetModel(model_);
	object_3->SetModel(model_);
	//�I�u�W�F�N�g�̏����ݒ�
	float scale = 2.0f;
	object_1->SetScale({ scale,scale,scale });
	object_2->SetScale({ scale,scale,scale });
	object_3->SetScale({ scale,scale,scale });

	object_1->Update();
	object_2->Update();
	object_3->Update();
}

void Enemy::Update()
{
	position_1 = { 0,+20,0 };
	position_2 = { -20,+20,0 };
	position_3 = { +20,+20,0 };

	object_1->SetPosition({ position_1.x,position_1.y,position_1.z });
	object_2->SetPosition({ position_2.x,position_2.y,position_2.z });
	object_3->SetPosition({ position_3.x,position_3.y,position_3.z });

	object_1->Update();
	object_2->Update();
	object_3->Update();

}



void Enemy::SpriteDraw()
{

}

void Enemy::ObjDraw()
{
	if(isDied == false)
	{
		object_1->Draw();
		object_2->Draw();
		object_3->Draw();
	}
}

XMFLOAT3 Enemy::GetPosition1()
{
	//���[���h���W������ϐ�
	XMFLOAT3 worldPos;
	//���[���h�s��̕��s�ړ��������擾

	worldPos.x = position_1.x;
	worldPos.y = position_1.y;
	worldPos.z = position_1.z;

	return worldPos;
}
XMFLOAT3 Enemy::GetPosition2()
{
	//���[���h���W������ϐ�
	XMFLOAT3 worldPos;
	//���[���h�s��̕��s�ړ��������擾

	worldPos.x = position_2.x;
	worldPos.y = position_2.y;
	worldPos.z = position_2.z;

	return worldPos;
}
XMFLOAT3 Enemy::GetPosition3()
{
	//���[���h���W������ϐ�
	XMFLOAT3 worldPos;
	//���[���h�s��̕��s�ړ��������擾

	worldPos.x = position_3.x;
	worldPos.y = position_3.y;
	worldPos.z = position_3.z;

	return worldPos;
}

void Enemy::OnCollision()
{
	isDied = true;
}