#pragma once
#include "WinApp.h"
#include "Input.h"
#include "DirectXCommon.h"
#include "Object3d.h"
#include "Model.h"
#include "Sprite.h"
#include "SpriteCommon.h"

#include <vector>

using namespace DirectX;


class Stage
{
public:
	//‰Šú‰»ˆ—
	void Initialize();
	//XVˆ—
	void Update();
	void MoveRot();

	//•`‰æˆ—
	void SpriteDraw();
	void ObjDraw();

private:
	Input* input_ = nullptr;
	
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 position_ = { 0.0f,0.0f,0.0f };
};