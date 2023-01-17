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

	//�G�e���X�g�̎擾
	const std::list<std::unique_ptr<EnemyBullet>>& enemyBullets = enemy_->GetBullet();

#pragma region ���L�����ƓG�e�̓����蔻��
	//���L�����̍��W
	posA = player_->GetPosition();

	//���L�����ƓG�e�S�Ă̓����蔻��
	for (const std::unique_ptr<EnemyBullet>& bullet : enemyBullets) {
		//�G�e�̍��W
		posB = bullet->GetPosition();

		const float AR = 2.0f;//A�̔��a
		const float BR = 2.0f;//B�̔��a

		float A = pow((posB.x - posA.x), 2) + pow((posB.y - posA.y), 2) + pow((posB.z - posA.z), 2);
		float B = pow((AR + BR), 2);

		if (A <= B) {
			//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
			player_->OnCollision();
			//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
			bullet->OnCollision();
			SceneNum = 2;
		}
	}
#pragma endregion

}