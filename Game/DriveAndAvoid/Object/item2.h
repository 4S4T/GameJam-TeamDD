#pragma once

#include"../Utility/Vector2D.h"

class Item2
{

private:
	//タイプ
	int type;
	//画像
	int image;
	//速さ
	float speed;
	//位置情報
	Vector2D location;
	//当たり判定の大きさ
	Vector2D box_size;
public:
	Item2(int type); //int handle);
	~Item2();

	//初期化処理
	void Initialize();
	//更新処理
	void Update(float speed);
	//描画処理
	void Draw() const;
	//終了時処理
	void Finalize();

	//タイプ取得
	int GetType() const;
	//位置情報の取得
	Vector2D GetLocation() const;
	//当たり判定の大きさを取得
	Vector2D GetBoxSize() const;
};

