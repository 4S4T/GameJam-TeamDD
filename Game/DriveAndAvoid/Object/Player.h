#pragma once

#include "../Utility/Vector2D.h"
#include "Barrier.h"

class Player
{
private:
	//有効状態か？
	bool is_active;
	//画像データ
	int image;
	//位置座標
	Vector2D location;
	//当たり判定の大きさ
	Vector2D box_size;
	//現在のレーン
	int lane;
	//速さ
	float speed;
	//体力
	float hp;
	//バリアの枚数
	int barrier_count;
	//バリア
	Barrier* barrier;

public:
	Player();
	~Player();

	//初期化処理
	void Initialize();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了時処理
	void Finalize();

public:
	//有効フラグ設定
	void SetActive(bool flg);
	//体力減少処理
	void DecreaseHp(float value);
	//位置座標取得
	Vector2D GetLocation()const;
	//当たり判定の大きさ取得
	Vector2D GetBoxSize()const;
	////速さ取得
	float GetSpeed()const;
	//体力取得
	float GetHp()const;
	//バリアの枚数取得
	int GetBarriarCount()const;
	//バリア有効か？を取得
	bool IsBarrier()const;
	//加速処理
	void Acceleration(float add);
	//ヤギ時の減少処理
	void YagiDecreHp(float value);

private:

	//移動処理
	void Movement();
	
};