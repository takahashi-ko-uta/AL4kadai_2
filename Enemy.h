#pragma once
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
	//�`�揈��
	void SpriteDraw();
	void ObjDraw();

private:
	Input* input_ = nullptr;
	Model* model_ = nullptr;
	Object3d* object3d = Object3d::Create();
	XMFLOAT3 Position = { 0.0f,0.0f,0.0f };

	//�����؂�ւ��̃^�C�}�[
	uint16_t moveTimer = 0;
	bool isMove = true;
	uint16_t moveDirection = 0;//1...��A2...���A3...���A4...�E
};