#include "Enemy1.h"
#include "DxLib.h"

Enemy1::Enemy1(int type) : Item_Base(type)
{
	
}

Enemy1::~Enemy1()
{

}

//初期化処理
void Enemy1::Initialize()
{

	image = LoadGraph("Resource/images/gomi_namagomi.png", image);

	//出現させるX座標パターン取得
	float random_y = (float)(GetRand(4) * 60 + 170);

	//生成位置の設定
	location = Vector2D(550.0f,random_y);

	//当たり判定の設定
	box_size = Vector2D(30.0f, 30.0f);

	//速さの設定
	speed = 1.0f; //(float)(this->type * 2);
}

void Enemy1::Draw() const
{

	//敵画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Enemy1::Finalize()
{

}

//敵のタイプを取得
int Enemy1::GetType() const
{

	return type;

}

//位置情報を取得
Vector2D Enemy1::GetLocation()const
{

	return location;

}

//当たり判定の大きさ取得
Vector2D Enemy1::GetBoxSize() const
{
	return box_size;
}