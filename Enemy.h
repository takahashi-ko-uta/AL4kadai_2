#pragma once
#include "WinApp.h"
#include "Input.h"
#include "Object3d.h"
#include "Model.h"

#include <vector>

using namespace DirectX;


class Enemy
{
public:
	//初期化処理
	void Initialize(Input* input);
	//更新処理
	void Update();
	void Move();
	//描画処理
	void SpriteDraw();
	void ObjDraw();

private:
	Input* input_ = nullptr;
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 Position = { 0.0f,0.0f,0.0f };

	//方向切り替えのタイマー
	uint16_t moveTimer = 0;
	bool isMove = true;
	uint16_t moveDirection = 0;//1...上、2...下、3...左、4...右
};