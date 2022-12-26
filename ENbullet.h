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
	// 衝突を検出したら呼び出されるコールバック関数
	void OnCollision();
	XMFLOAT3 GetPosition();


	void Draw();

	bool IsDead() const { return isDead_; }
	float radius = 3.0f;
private:
	//速度
	float speed = 0.5f;
	//寿命
	static const int32_t kLifeTime = 60 * 5;
	//デスタイマー
	int32_t deathTimer_ = kLifeTime;
	//デスフラグ
	bool isDead_ = false;
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 position_ = { 0.0f,0.0f,0.0f };
};

