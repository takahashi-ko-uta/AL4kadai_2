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

	//オブジェクトを指定
	model_title = Model::LoadFromOBJ("title");
	model_ending = Model::LoadFromOBJ("ending");
	//3Dオブジェクトと3Dモデルを紐づける
	objTitle->SetModel(model_title);
	objEnding->SetModel(model_ending);

	player_->Initialize(input_);
	enemy_->Initialize(input_);
	stage_->Initialize();
}

void GameScene::Update()
{
	//SceneNum = 0;
	switch (SceneNum)
	{
	case 0:
		TitleUpdate();
		break;
	case 1:
		GameUpdate();
			break;
	case 2:
		EndingUpdate();
			break;
	}
}

void GameScene::TitleUpdate()
{
	float scale = 10.0f;
	objTitle->SetPosition({ -23.0f,0.0f,0.0f });
	objTitle->SetScale({ scale, scale, scale });
	objTitle->SetRotation({ 0.0f,180.0f,0.0f });
	objTitle->Update();
	if(input_->PushKey(DIK_SPACE))
	{
		SceneNum = 1;
	}
}

void GameScene::GameUpdate()
{
	player_->Update();
	enemy_->Update();
	stage_->Update();
	//当たり判定
	CheckAllCollisons();
}

void GameScene::EndingUpdate()
{
	float scale = 10.0f;
	objEnding->SetScale({ scale, scale, scale });
	objEnding->SetRotation({ 0.0f,180.0f,0.0f });
	objEnding->Update();
	
	const uint16_t interval = 120;
	if(isEnding = true)
	{
		endTimer++;
		if(endTimer >= interval)
		{
			SceneNum = 0;
			isEnding = false;
			endTimer = 0;
		}
	}

}

void GameScene::SpriteDraw()
{
	player_->SpriteDraw();
	enemy_->SpriteDraw();
	stage_->SpriteDraw();
}

void GameScene::ObjDraw()
{
	switch (SceneNum)
	{
	case 0:
		objTitle->Draw();
		break;
	case 1:
		player_->ObjDraw();
		enemy_->ObjDraw();
		stage_->ObjDraw();
		break;
	case 2:
		objEnding->Draw();
		break;
	}

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