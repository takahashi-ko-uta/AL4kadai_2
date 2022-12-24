#pragma once
#include "WinApp.h"
#include "Input.h"
#include "DirectXCommon.h"
#include "Object3d.h"
#include "Model.h"
#include "Sprite.h"
#include "SpriteCommon.h"

#include <vector>

using namespace DirectX;


class Stage
{
public:
	//����������
	void Initialize(Input* input, SpriteCommon* spriteCommon);
	//�X�V����
	void Update();

	//�`�揈��
	void SpriteDraw();
	void ObjDraw();

private:
	Input* input_ = nullptr;
	SpriteCommon* spriteCommon_ = nullptr;
	//SpriteCommon* spriteCommon_= new SpriteCommon();
	Sprite* sprite_stage1 = new Sprite();
	Sprite* sprite_stage2 = new Sprite();
	Sprite* sprite_stage3 = new Sprite();
	
};