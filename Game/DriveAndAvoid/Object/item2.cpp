#include "Item2.h"
#include "DxLib.h"

Item2::Item2(int type) : Item_Base(type)
{
	
}

Item2::~Item2()
{

}

//初期化処理
void Item2::Initialize(int set_lane)
{

	image = LoadGraph("Resource/images/food_maguro_saku2.png", image);

	//出現させるX座標パターン取得
	float random_y = (float)(set_lane * 60 + 170);

	//生成位置の設定
	location = Vector2D(550.0f, random_y);

	//当たり判定の設定
	box_size = Vector2D(30.0f, 30.0f);

	//速さの設定
	speed = 4.0f; //(float)(this->type * 2);
}

void Item2::Draw() const
{

	//敵画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Item2::Finalize()
{

}

//敵のタイプを取得
int Item2::GetType() const
{

	return type;

}

//位置情報を取得
Vector2D Item2::GetLocation()const
{

	return location;

}

//当たり判定の大きさ取得
Vector2D Item2::GetBoxSize() const
{
	return box_size;
}