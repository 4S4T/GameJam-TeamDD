#pragma once

#include"../Utility/Vector2D.h"
#include"Item_Base.h"

class Enemy1 :public Item_Base
{
public:
	Enemy1(int type); //int handle);
	~Enemy1();

	//初期化処理
	void Initialize();
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

