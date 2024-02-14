#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include "../Object/Item.h"
#include"../Object/Item2.h"

class GameMainScene :public SceneBase
{

private:

	//ハイスコア
	int high_score;
	//背景画像
	int back_ground;
	//バリア画像
	int barrier_image;
	//走行距離
	int mileage;
	//敵画像
	int enemy_image[3];
	
	//通り過ぎた敵COUNT
	int enemy_count[3];
	//プレイヤー
	Player* player;
	//敵
	Enemy** enemy;

	//アイテム
	Item* item;

	int item_image;

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:

	//ハイスコア読み込み処理
	void ReadHighScore();
	//当たり判定
	bool IsHitCheck(Player* p, Enemy* e);
	bool IsHitCheck2(Player* p, Item* i);
};