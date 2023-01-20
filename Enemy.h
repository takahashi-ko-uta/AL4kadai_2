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
	static int isDied;
public:
	//‰Šú‰»ˆ—
	void Initialize(Input* input);
	//XVˆ—
	void Update();
	
	void Reset();
	//•`‰æˆ—
	void SpriteDraw();
	void ObjDraw();
	XMFLOAT3 GetPosition();
	void SetPosision(XMFLOAT3 pos) { position_ = pos; }

	void OnCollision();
	
private:
	Input* input_ = nullptr;
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	
	XMFLOAT3 position_ = { 0.0f,0.0f,0.0f };
	
	
	
};