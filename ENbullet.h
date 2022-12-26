#pragma once
#include "ENbullet.h"
#include "WinApp.h"
#include "Input.h"
#include "Object3d.h"
#include "Model.h"
#include <vector>

using namespace DirectX;

class EnemyBullet {
public:
	void Initialize(Model* model, const XMFLOAT3& position);

	void Update();
	// �Փ˂����o������Ăяo�����R�[���o�b�N�֐�
	void OnCollision();
	XMFLOAT3 GetPosition();


	void Draw();

	bool IsDead() const { return isDead_; }
	float radius = 3.0f;
private:
	//���x
	float speed = 0.5f;
	//����
	static const int32_t kLifeTime = 60 * 5;
	//�f�X�^�C�}�[
	int32_t deathTimer_ = kLifeTime;
	//�f�X�t���O
	bool isDead_ = false;
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 position_ = { 0.0f,0.0f,0.0f };
};

