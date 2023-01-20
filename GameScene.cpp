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

	//�I�u�W�F�N�g���w��
	model_title = Model::LoadFromOBJ("title");
	model_ending = Model::LoadFromOBJ("ending");
	//3D�I�u�W�F�N�g��3D���f����R�Â���
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
	//�����蔻��
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
	//����Ώ�A��B�̍��W
	XMFLOAT3 posA, posB;
	const float AR = 2.0f;//A�̔��a
	const float BR = 2.0f;//B�̔��a

#pragma region ���L�����ƓG�L����1�̓����蔻��
	//���L�����̍��W
	posA = player_->GetPosition();

	posB = enemy_1->GetPosition();

	float A1 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B1 = pow((AR + BR), 2);

	if (A1 <= B1) {
		//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
		player_->OnCollision();
		//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
		enemy_1->OnCollision();
		SceneNum = 2;
	}
#pragma endregion

#pragma region ���L�����ƓG�L����2�̓����蔻��
	//���L�����̍��W
	posA = player_->GetPosition();

	posB = enemy_2->GetPosition();

	float A2 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B2 = pow((AR + BR), 2);

	if (A2 <= B2) {
		//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
		player_->OnCollision();
		//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
		enemy_2->OnCollision();
		SceneNum = 2;
	}
#pragma endregion

#pragma region ���L�����ƓG�L����3�̓����蔻��
	//���L�����̍��W
	posA = player_->GetPosition();

	posB = enemy_3->GetPosition();

	float A3 = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
	float B3 = pow((AR + BR), 2);

	if (A3 <= B3) {
		//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
		player_->OnCollision();
		//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
		enemy_3->OnCollision();
		SceneNum = 2;
	}
#pragma endregion
}