#pragma once

#include "SceneBase.h"
#include"..//Object/RankingData.h"

class RankingInputScene : public SceneBase
{
private:
	//背景画像
	int background_image;
	//ランキング情報
	RankingData* ranking;
	//スコア
	int score;
	//名前
	char name[15];
	//名前入力数
	int name_num;
	//カーソルX座標
	int cursor_x;
	//カーソルY座標
	int cursor_y;

public:
	RankingInputScene();
	virtual ~RankingInputScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	//名前入力処理
	bool InputName();
};