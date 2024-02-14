#include "Item.h"
#include "DxLib.h"

Item::Item(int type) : type(type), image(), speed(0.0f), location(0.0f), box_size(0.0f)
{

}

Item::~Item()
{

}

//初期化処理
void Item::Initialize()
{

	//image = LoadGraph("Resource/images/car.png", image);

	//出現させるX座標パターン取得
	float random_x = (float)(GetRand(4) * 105 + 40);

	//生成位置の設定
	location = Vector2D(random_x, -50.0f);

	//当たり判定の設定
	box_size = Vector2D(31.0f, 60.0f);

	//速さの設定
	speed = 1.0f; //(float)(this->type * 2);
}

void Item::Update(float speed)
{

	//位置情報に移動量を加算する
	location += Vector2D(0.0f, this->speed + speed);// + speed - 6);

}
void Item::Draw() const
{

	//敵画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, type, TRUE);

}

void Item::Finalize()
{

}

//敵のタイプを取得
int Item::GetType() const
{

	return type;

}

//位置情報を取得
Vector2D Item::GetLocation()const
{

	return location;

}

//当たり判定の大きさ取得
Vector2D Item::GetBoxSize() const
{
	return box_size;
}