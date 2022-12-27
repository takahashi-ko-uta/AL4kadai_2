#include "ENbullet.h"

void EnemyBullet::Initialize(Model* model, const XMFLOAT3& position)
{
	//�����Ŏ󂯎�����������W���Z�b�g
	position_ = position;

	//�I�u�W�F�N�g���w��
	model_ = model;
	//3D�I�u�W�F�N�g��3D���f����R�Â���
	object3d->SetModel(model_);
	//�I�u�W�F�N�g�̏����ݒ�
	float scale = 2.0f;
	object3d->SetScale({ scale,scale,scale });
	object3d->SetPosition(position_);
	object3d->Update();
	
}


void EnemyBullet::Update() 
{
	//position_.z -= speed;
	position_.x += speed;
	//���f
	object3d->SetPosition(position_);
	object3d->Update();

	//���Ԍo�߂ŏ�����
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
}

void EnemyBullet::OnCollision()
{
	isDead_ = true;
}

XMFLOAT3 EnemyBullet::GetPosition() 
{
	//���[���h���W������ϐ�
	XMFLOAT3 worldPos;
	//���[���h�s��̕��s�ړ��������擾

	worldPos.x = position_.x;
	worldPos.y = position_.y;
	worldPos.z = position_.z;

	return worldPos;
}



void EnemyBullet::Draw()
{
	object3d->Draw();
}