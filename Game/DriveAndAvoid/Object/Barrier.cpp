#include "Barrier.h"
#include "DxLib.h"

Barrier::Barrier() : life_span(1000)
{
	//画像読み込み
	LoadDivGraph("Resource/images/pakupakuneko.png", 6, 6, 1, 70, 88, image);

	//エラーチェック
	//if (image == -1)
	//{
	//	throw ("Resource/images/barrier.pngがありません/n");
	//}
}

Barrier::~Barrier()
{
	//余も込んだ画像を削除
	DeleteGraph(image[6]);
}

//描画処理
void Barrier::Draw(const Vector2D& location)
{

	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image[0], TRUE);
}

//寿命が尽きたか？
bool Barrier::IsFinished(float speed)
{
	life_span -= speed;
	return (life_span <= 0);
}