#include "Stage.h"
#include <stdio.h>
#include <time.h>
#define PI 3.14159

void Stage::Initialize()
{
	//�I�u�W�F�N�g���w��
	model_ = Model::LoadFromOBJ("skydome");
	//3D�I�u�W�F�N�g��3D���f����R�Â���
	object3d->SetModel(model_);
	//�I�u�W�F�N�g�̏����ݒ�
	float scale = 70.0f;
	object3d->SetScale({ scale,scale,scale });
	object3d->Update();
}

void Stage::Update()
{
	MoveRot();
}

void Stage::MoveRot()
{
	object3d->Update();
}

void Stage::SpriteDraw()
{

}
	

void Stage::ObjDraw()
{
	object3d->Draw();
}