#pragma once

#include "SceneBase.h"

class ResultScene : public SceneBase
{
private:
	//”wŒi‰æ‘œ
	int back_ground;
	//ƒXƒRƒA
	int score;
	//‹——£
	int mileage;
	//“G‚ÌƒJƒEƒ“ƒg
	int enemy_count[3];
	//“G‰æ‘œ
	int enemy_image[3];

	int SE;
	int SE_fanf;

public:
	ResultScene();
	virtual ~ResultScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	void ReadResultData();
};