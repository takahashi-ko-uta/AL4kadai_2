#include "GameScene.h"

#define PI 3.14159

GameScene::GameScene(){}
GameScene::~GameScene()
{
	delete player_;
	delete enemy_1;
	delete enemy_2;
	delete enemy_3;
	delete stage_;
}

void GameScene::Initialize(Input* input, SpriteCommon* spriteCommon)
{
	input_ = input;
	spriteCommon_ = spriteCommon;

	//オブジェクトを指定
	model_title = Model::LoadFromOBJ("title");
	model_ending = Model::LoadFromOBJ("ending");
	//3Dオブジェクトと3Dモデルを紐づける
	objTitle->SetModel(model_title);
	objEnding->SetModel(model_ending);

	player_->Initialize(input_);
	enemy_1->Initialize(input_);
	enemy_2->Initialize(input_);
	enemy_3->Initialize(input_);
	stage_->Initialize();
}

void GameScene::Update()
{
	GameUpdate();
}


void GameScene::GameUpdate()
{
	player_->Update();
	enemy_1->Update();
	enemy_2->Update();
	enemy_3->Update();
	stage_->Update();
	//当たり判定
	CheckAllCollisons();
}


void GameScene::SpriteDraw()
{
	player_->SpriteDraw();
	enemy_1->SpriteDraw();
	stage_->SpriteDraw();
}

void GameScene::ObjDraw()
{
	player_->ObjDraw();
	enemy_1->ObjDraw();
	enemy_2->ObjDraw();
	enemy_3->ObjDraw();
	stage_->ObjDraw();

}


void GameScene::CheckAllCollisons()
{
	//判定対象AとBの座標
	XMFLOAT3 posA, posB;
	const float AR = 2.0f;//Aの半径
	const float BR = 2.0f;//Bの半径

#pragma region 自キャラと敵キャラ1の当たり判定
	//自キャラの座標
	posA = player_->GetPosition();

	posB = enemy_1->GetPosition();

	float A1 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B1 = pow((AR + BR), 2);

	if (A1 <= B1) {
		//自キャラの衝突時コールバックを呼び出す
		player_->OnCollision();
		//敵弾の衝突時コールバックを呼び出す
		enemy_1->OnCollision();
		SceneNum = 2;
	}
#pragma endregion

#pragma region 自キャラと敵キャラ2の当たり判定
	//自キャラの座標
	posA = player_->GetPosition();

	posB = enemy_2->GetPosition();

	float A2 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B2 = pow((AR + BR), 2);

	if (A2 <= B2) {
		//自キャラの衝突時コールバックを呼び出す
		player_->OnCollision();
		//敵弾の衝突時コールバックを呼び出す
		enemy_2->OnCollision();
		SceneNum = 2;
	}
#pragma endregion

#pragma region 自キャラと敵キャラ3の当たり判定
	//自キャラの座標
	posA = player_->GetPosition();

	posB = enemy_3->GetPosition();

	float A3 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B3 = pow((AR + BR), 2);

	if (A3 <= B3) {
		//自キャラの衝突時コールバックを呼び出す
		player_->OnCollision();
		//敵弾の衝突時コールバックを呼び出す
		enemy_3->OnCollision();
		SceneNum = 2;
	}
#pragma endregion
}