#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"

class GameMainScene :public SceneBase
{

private:

	//nCXRA
	int high_score;
	//wiæ
	int back_ground;
	//oAæ
	int barrier_image;
	//s£
	int mileage;
	//Gæ
	int enemy_image[3];
	int Enemy_image[6];
	//Êèß¬½GCOUNT
	int enemy_count[3];
	//vC[
	Player* player;
	//G
	Enemy** enemy;

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:

	//nCXRAÇÝÝ
	void ReadHighScore();
	//½è»è
	bool IsHitCheck(Player* p, Enemy* e);
};