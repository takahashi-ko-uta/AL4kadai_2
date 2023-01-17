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
	//����������
	void Initialize(Input* input);
	//�X�V����
	void Update();
	void Move();
	void Attack();
	
	//�`�揈��
	void SpriteDraw();
	void ObjDraw();

	const std::list<std::unique_ptr<EnemyBullet>>& GetBullet() { return bullets_; }

	//���상���o�֐�
	void Approach();
	void Shot();
	void Leave();
private:
	Input* input_ = nullptr;
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 position_ = { 0.0f,0.0f,0.0f };

	//�����؂�ւ��̃^�C�}�[
	uint16_t moveTimer = 0;
	bool isMove = true;
	uint16_t moveDirection = 0;//1...��A2...���A3...���A4...�E

	//�e
	std::list<std::unique_ptr<EnemyBullet>> bullets_;
	
	//�U���̃^�C�}�[
	uint16_t atttackTimer = 0;
	bool isAttack = false;

	//�����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* spFuncTamle[])();
	uint16_t moveNum = 0;
};