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

	//����������
	void Initialize(Input* input, SpriteCommon* spriteCommon);
	//�X�V����
	void Update();
	//�`�揈��
	void SpriteDraw();
	void ObjDraw();

	//�����蔻��
	void CheckAllCollisons();

private:
	Input* input_ = nullptr;
	SpriteCommon* spriteCommon_ = nullptr;
	DirectXCommon* dxCommon_ = nullptr;
	//�e�N���X�̌Ăяo��
	Player* player_ = new Player();
	Enemy* enemy_ = new Enemy();
	Stage* stage_ = new Stage();
};

