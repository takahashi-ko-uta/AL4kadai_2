//#include "enemy.h"
//#include <stdio.h>
//#include <time.h>
//
//void Enemy::Initialize(Input* input)
//{
//	input_ = input;
//	//�I�u�W�F�N�g���w��
//	model_ = Model::LoadFromOBJ("enemy");
//	//3D�I�u�W�F�N�g��3D���f����R�Â���
//	object3d->SetModel(model_);
//	//�I�u�W�F�N�g�̏����ݒ�
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
//	//�����𒊑I
//	if (isMove == true)
//	{
//		++moveTimer;
//		if (moveTimer >= interval)
//		{
//			moveDirection = rand() % 4 + 1;//1�`4���擾
//			isMove = false;
//		}
//	}
//
//	//�ړ�
//	switch (moveDirection)
//	{
//	case 1://��
//		Position.y += speed;
//		isMove = true;
//		break;
//	case 2://��
//		Position.y -= speed;
//		isMove = true;
//		break;
//	case 3://��
//		Position.x -= speed;
//		isMove = true;
//		break;
//	case 4://�E
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