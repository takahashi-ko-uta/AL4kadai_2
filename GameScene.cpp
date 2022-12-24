#include "GameScene.h"

GameScene::GameScene(){}
GameScene::~GameScene()
{
	delete player_;
	delete enemy_;
}

void GameScene::Initialize(Input* input, DirectXCommon* dxCommon)
{
	input_ = input;
	dxCommon_ = dxCommon;
	player_->Initialize(input_);
	enemy_->Initialize(input_);
}

void GameScene::Update()
{
	player_->Update();
	enemy_->Update();
}

void GameScene::SpriteDraw()
{
	player_->SpriteDraw();
	enemy_->SpriteDraw();
}

void GameScene::ObjDraw()
{
	player_->ObjDraw();
	enemy_->ObjDraw();
}
