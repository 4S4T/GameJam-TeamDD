#pragma once
#pragma once

#include"../Utility/Vector2D.h"
#include"Item_Base.h"

class Item3 : public Item_Base
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
	Item3(int type); //int handle);
	~Item3();

	//初期化処理
	void Initialize(int set_lane) override;
	//描画処理
	void Draw() const override;
	//終了時処理
	void Finalize();

	//タイプ取得
	int GetType() const;
	//位置情報の取得
	Vector2D GetLocation() const override;
	//当たり判定の大きさを取得
	Vector2D GetBoxSize() const override;
};

