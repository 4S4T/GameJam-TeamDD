#include "Item2.h"
#include "DxLib.h"

Item2::Item2(int type) : type(type), image(), speed(0.0f), location(0.0f), box_size(0.0f)
{

}

Item2::~Item2()
{

}

//初期化処理
void Item2::Initialize()
{

	image = LoadGraph("Resource/images/food_maguro_saku2.png");

	//出現させるX座標パターン取得
	float random_y = (float)(GetRand(4) * 50 + 150);

	//生成位置の設定
	location = Vector2D(550.0f,random_y);

	//当たり判定の設定
	box_size = Vector2D(31.0f, 60.0f);

	//速さの設定
	speed = 1.0f; //(float)(this->type * 2);
}

void Item2::Update(float speed)
{

	//位置情報に移動量を加算する
	location -= Vector2D( this->speed + speed,0.0f);// + speed - 6);

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