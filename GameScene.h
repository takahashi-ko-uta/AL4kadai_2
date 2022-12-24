#pragma once
#include "Player.h"
#include "Enemy.h"
#include "GameScene.h"

#include "Input.h"
#include "Object3d.h"
#include "Model.h"
#include "DirectXCommon.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	void Initialize(Input* input, DirectXCommon* dxCommon);
	void Update();
	void SpriteDraw();
	void ObjDraw();

private:
	Input* input_ = nullptr;
	DirectXCommon* dxCommon_ = nullptr;
	//各クラスの呼び出し
	Player* player_ = new Player();
	Enemy* enemy_ = new Enemy();
};

