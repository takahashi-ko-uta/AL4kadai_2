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

	//�I�u�W�F�N�g���w��
	model_title = Model::LoadFromOBJ("title");
	model_ending = Model::LoadFromOBJ("ending");
	//3D�I�u�W�F�N�g��3D���f����R�Â���
	objTitle->SetModel(model_title);
	objEnding->SetModel(model_ending);

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
	//�����蔻��
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
	//����Ώ�A��B�̍��W
	XMFLOAT3 posA, posB;
	const float AR = 2.0f;//A�̔��a
	const float BR = 2.0f;//B�̔��a

#pragma region ���L�����ƓG�L����1�̓����蔻��
	//���L�����̍��W
	posA = player_->GetPosition();

	posB = enemy_->GetPosition1();

	float A1 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B1 = pow((AR + BR), 2);

	if (A1 <= B1) {
		//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
		player_->OnCollision();
		//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
		enemy_->OnCollision();
		SceneNum = 2;
	}
#pragma endregion

#pragma region ���L�����ƓG�L����2�̓����蔻��
	//���L�����̍��W
	posA = player_->GetPosition();

	posB = enemy_->GetPosition2();

	float A2 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B2 = pow((AR + BR), 2);

	if (A2 <= B2) {
		//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
		player_->OnCollision();
		//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
		enemy_->OnCollision();
		SceneNum = 2;
	}
#pragma endregion

#pragma region ���L�����ƓG�L����3�̓����蔻��
	//���L�����̍��W
	posA = player_->GetPosition();

	posB = enemy_->GetPosition3();

	float A3 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B3 = pow((AR + BR), 2);

	if (A3 <= B3) {
		//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
		player_->OnCollision();
		//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
		enemy_->OnCollision();
		SceneNum = 2;
	}
#pragma endregion

}