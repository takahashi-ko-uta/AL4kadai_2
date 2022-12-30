#include "Stage.h"
#include <stdio.h>
#include <time.h>
#define PI 3.14159

void Stage::Initialize()
{
	//オブジェクトを指定
	model_ = Model::LoadFromOBJ("skydome");
	//3Dオブジェクトと3Dモデルを紐づける
	object3d->SetModel(model_);
	//オブジェクトの初期設定
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