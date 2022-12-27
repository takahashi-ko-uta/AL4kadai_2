#include "ENbullet.h"

void EnemyBullet::Initialize(Model* model, const XMFLOAT3& position)
{
	//引数で受け取った初期座標をセット
	position_ = position;

	//オブジェクトを指定
	model_ = model;
	//3Dオブジェクトと3Dモデルを紐づける
	object3d->SetModel(model_);
	//オブジェクトの初期設定
	float scale = 2.0f;
	object3d->SetScale({ scale,scale,scale });
	object3d->SetPosition(position_);
	object3d->Update();
	
}


void EnemyBullet::Update() 
{
	//position_.z -= speed;
	position_.x += speed;
	//反映
	object3d->SetPosition(position_);
	object3d->Update();

	//時間経過で消える
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
	//ワールド座標を入れる変数
	XMFLOAT3 worldPos;
	//ワールド行列の平行移動成分を取得

	worldPos.x = position_.x;
	worldPos.y = position_.y;
	worldPos.z = position_.z;

	return worldPos;
}



void EnemyBullet::Draw()
{
	object3d->Draw();
}