#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include"../Object/Item_Base.h"
#include "../Object/Item.h"
#include"..//Object/Item2.h"
#include"../Object/Enemy1.h"
#include"../Object/Enemy2.h"
#include"../Object/Enemy3.h"
#include"..//Object/Item3.h"

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

	//アイテム


	Item_Base* item_base[8];
	int flame;
	int second;
	int CreateFps;

	int item_spawn_rate;
	int item_spawn_max;

	bool Matatabi_Flg;
	int Matatabi_cnt;
	int Matatabi_Time;

	bool YagiFlg;
	int YagiWaitTime;
	int YagiFps;

	int kira;
	int bisi;

	int BGM;
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
	bool IsHitItem(Player* p, Item_Base* i);
};