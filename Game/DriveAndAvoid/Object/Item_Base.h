#pragma once

#include"../Utility/Vector2D.h"

class Item_Base
{
protected:
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
	Item_Base(int type);
	~Item_Base();

	//初期化処理
	virtual void Initialize();
	//更新処理
	void Update(float speed);
	//描画処理
	virtual void Draw() const;
	//終了時処理
	void Finalize();

	//タイプ取得
	int GetType() const;
	//位置情報の取得
	virtual Vector2D GetLocation() const;
	//当たり判定の大きさを取得
	virtual Vector2D GetBoxSize() const;
};

