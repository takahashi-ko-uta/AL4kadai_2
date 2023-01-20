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
	//初期化処理
	void Initialize(Input* input);
	//更新処理
	void Update();
	
	void Reset();
	//描画処理
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
	

	bool isDied = false;
};