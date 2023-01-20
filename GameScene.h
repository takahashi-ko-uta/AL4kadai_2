#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Stage.h"

#include "Input.h"
#include "Object3d.h"
#include "Model.h"
#include "DirectXCommon.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	//初期化処理
	void Initialize(Input* input, SpriteCommon* spriteCommon);
	//更新処理
	void Update();
	void GameUpdate();
	//描画処理
	void SpriteDraw();
	void ObjDraw();

	//当たり判定
	void CheckAllCollisons();
private:
	Input* input_ = nullptr;
	SpriteCommon* spriteCommon_ = nullptr;
	DirectXCommon* dxCommon_ = nullptr;
	//各クラスの呼び出し
	Player* player_ = new Player();
	Enemy* enemy_1 = new Enemy();
	Enemy* enemy_2 = new Enemy();
	Enemy* enemy_3 = new Enemy();
	Stage* stage_ = new Stage();

	uint16_t SceneNum = 0;//0...タイトル 1...ゲーム 3...エンディング

	Model* model_title = nullptr;
	Object3d* objTitle = Object3d::Create();

	Model* model_ending = nullptr;
	Object3d* objEnding = Object3d::Create();
	bool isEnding = false;
	uint16_t endTimer = 0;
};

