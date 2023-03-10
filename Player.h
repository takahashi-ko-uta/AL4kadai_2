#pragma once
#include "WinApp.h"
#include "Input.h"
#include "Object3d.h"
#include "Model.h"

#include <vector>

using namespace DirectX;


class Player
{
public:
	//初期化処理
	void Initialize(Input* input);
	//更新処理
	void Update();
	void Move();
	void Reset();
	//描画処理
	void SpriteDraw();
	void ObjDraw();

	void OnCollision();

	XMFLOAT3 GetPosition();

private:
	Input* input_ = nullptr;
	
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 position_ = {0.0f,0.0f,0.0f};

	float radius = 3.0f;
};

