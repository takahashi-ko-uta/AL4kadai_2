#include "GameScene.h"

#define PI 3.14159

GameScene::GameScene(){}
GameScene::~GameScene()
{
	delete player_;
	delete enemy_;
	delete stage_;
}

void GameScene::Initialize(Input* input, SpriteCommon* spriteCommon)
{
	input_ = input;
	spriteCommon_ = spriteCommon;

	player_->Initialize(input_);
	enemy_->Initialize(input_);
	stage_->Initialize();
}

void GameScene::Update()
{
	GameUpdate();
}

void GameScene::GameUpdate()
{
	player_->Update();
	enemy_->Update();
	stage_->Update();
	//当たり判定
	CheckAllCollisons();
}

void GameScene::SpriteDraw()
{
	player_->SpriteDraw();
	enemy_->SpriteDraw();
	stage_->SpriteDraw();
}

void GameScene::ObjDraw()
{
	player_->ObjDraw();
	enemy_->ObjDraw();
	stage_->ObjDraw();
}


void GameScene::CheckAllCollisons()
{
	//判定対象AとBの座標
	XMFLOAT3 posA, posB;

	//敵弾リストの取得
	const std::list<std::unique_ptr<EnemyBullet>>& enemyBullets = enemy_->GetBullet();

#pragma region 自キャラと敵弾の当たり判定
	//自キャラの座標
	posA = player_->GetPosition();

	//自キャラと敵弾全ての当たり判定
	for (const std::unique_ptr<EnemyBullet>& bullet : enemyBullets) {
		//敵弾の座標
		posB = bullet->GetPosition();

		const float AR = 2.0f;//Aの半径
		const float BR = 2.0f;//Bの半径

		float A = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
		float B = pow((AR + BR), 2);

		if (A <= B) {
			//自キャラの衝突時コールバックを呼び出す
			player_->OnCollision();
			//敵弾の衝突時コールバックを呼び出す
			bullet->OnCollision();
			SceneNum = 2;
		}
	}
#pragma endregion

}