#include "GameScene.h"

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
	stage_->Initialize(input_, spriteCommon_);
}

void GameScene::Update()
{
	player_->Update();
	enemy_->Update();
	stage_->Update();
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
