#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include "../Object/Item.h"
#include"../Object/Item2.h"
#include"../Object/Enemy1.h"
#include"../Object/Enemy2.h"
#include"../Object/Enemy3.h"

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
	Item2* item2;
	Enemy1* enemy1;
	Enemy2* enemy2;
	Enemy3* enemy3;

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
	bool IsHitCheck3(Player* p, Item2* i2);
	bool IsHitCheck4(Player* p, Enemy1* e1);
	bool IsHitCheck5(Player* p, Enemy2* e2);
	bool IsHitCheck6(Player* p, Enemy3* e3);
};