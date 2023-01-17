#pragma once
#include "ENbullet.h"
#include "WinApp.h"
#include "Input.h"
#include "Object3d.h"
#include "Model.h"

#include <vector>

using namespace DirectX;


class Enemy
{
public:
	//‰Šú‰»ˆ—
	void Initialize(Input* input);
	//XVˆ—
	void Update();
	
	void Reset();
	//•`‰æˆ—
	void SpriteDraw();
	void ObjDraw();
	XMFLOAT3 GetPosition1();
	XMFLOAT3 GetPosition2();
	XMFLOAT3 GetPosition3();
	void OnCollision();
	
private:
	Input* input_ = nullptr;
	Model* model_ = nullptr;
	Object3d* object_1 = Object3d::Create();
	Object3d* object_2 = Object3d::Create(); 
	Object3d* object_3 = Object3d::Create();
	XMFLOAT3 position_1 = { 0.0f,0.0f,0.0f };
	XMFLOAT3 position_2 = { 0.0f,0.0f,0.0f };
	XMFLOAT3 position_3 = { 0.0f,0.0f,0.0f };

	bool isDied = false;
};