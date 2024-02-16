#include "Item_Base.h"
#include "DxLib.h"

Item_Base::Item_Base(int type) : type(type), image(), speed(0.0f), location(0.0f), box_size(0.0f)
{
	//image = 0; speed = 0.0f; location = (0.0f); box_size = (0.0f);
}

Item_Base::~Item_Base()
{

}

//初期化処理
void Item_Base::Initialize(int set_lane)
{

	image = LoadGraph("Resource/images/car.png", image);

	//出現させるX座標パターン取得
	float random_y = (float)(set_lane * 60 + 170);

	//生成位置の設定
	location = Vector2D(550.0f, random_y);

	//当たり判定の設定
	box_size = Vector2D(30.0f, 30.0f);

	//速さの設定
	speed = 1.0f; //(float)(this->type * 2);
}

void Item_Base::Update(float speed)
{

	//位置情報に移動量を加算する
	location -= Vector2D(this->speed + speed, 0.0f);// + speed - 6);

}
void Item_Base::Draw() const
{

	//敵画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Item_Base::Finalize()
{

}

//敵のタイプを取得
int Item_Base::GetType() const
{

	return type;

}

//位置情報を取得
Vector2D Item_Base::GetLocation()const
{

	return location;

}

//当たり判定の大きさ取得
Vector2D Item_Base::GetBoxSize() const
{
	return box_size;
}