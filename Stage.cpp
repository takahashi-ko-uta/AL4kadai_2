#include "Stage.h"
#include <stdio.h>
#include <time.h>

void Stage::Initialize(Input* input, SpriteCommon* spriteCommon)
{
	input_ = input;
	spriteCommon_ = spriteCommon;
	sprite_stage1 = new Sprite();
	sprite_stage1->SetTextureIndex(2);
	sprite_stage1->Initialize(spriteCommon_, 2);
	//sprite‚Ì‰ŠúÝ’è
	float size = 50.0f;
	sprite_stage1->SetSize({ size,size });
	sprite_stage1->Update();
}

void Stage::Update()
{
	sprite_stage1->Update();
	
}


void Stage::SpriteDraw()
{
	sprite_stage1->Draw();
}

void Stage::ObjDraw()
{
	
}