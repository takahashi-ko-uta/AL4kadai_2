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
	//�����蔻��
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