#pragma once

#include "SceneBase.h"

class TitleScene : public SceneBase
{
private:

private:

	//背景画像
	int background_image;
	//メニュー画像
	int menu_image;
	//カーソル画像
	int cursor_image;
	//メニューカーソル番号
	int menu_cursor;

	// タイトルの配列
	int gMenu[4];

	// フォント
	int font1;

public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize()override;

	virtual eSceneType GetNowScene() const override;
};