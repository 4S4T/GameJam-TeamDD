#pragma once

#include "SceneBase.h"

class ResultScene : public SceneBase
{
private:
	//�w�i�摜
	int back_ground;
	//�X�R�A
	int score;
	//����
	int mileage;
	//�G�̃J�E���g
	int enemy_count[3];
	//�G�摜
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