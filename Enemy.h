#pragma once
#include "ENbullet.h"
#include "WinApp.h"
#include "Input.h"
#include "Object3d.h"
#include "Model.h"

#include <vector>

using namespace DirectX;


class Enemy
{
public:
	//初期化処理
	void Initialize(Input* input);
	//更新処理
	void Update();
	void Move();
	void Attack();
	
	//描画処理
	void SpriteDraw();
	void ObjDraw();

	const std::list<std::unique_ptr<EnemyBullet>>& GetBullet() { return bullets_; }

	//自作メンバ関数
	void Approach();
	void Shot();
	void Leave();
private:
	Input* input_ = nullptr;
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 position_ = { 0.0f,0.0f,0.0f };

	//方向切り替えのタイマー
	uint16_t moveTimer = 0;
	bool isMove = true;
	uint16_t moveDirection = 0;//1...上、2...下、3...左、4...右

	//弾
	std::list<std::unique_ptr<EnemyBullet>> bullets_;
	
	//攻撃のタイマー
	uint16_t atttackTimer = 0;
	bool isAttack = false;

	//メンバ関数ポインタのテーブル
	static void (Enemy::* spFuncTamle[])();
	uint16_t moveNum = 0;
};