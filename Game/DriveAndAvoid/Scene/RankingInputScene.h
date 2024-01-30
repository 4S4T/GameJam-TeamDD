#pragma once

#include "SceneBase.h"
#include"..//Object/RankingData.h"

class RankingInputScene : public SceneBase
{
private:
	//�w�i�摜
	int background_image;
	//�����L���O���
	RankingData* ranking;
	//�X�R�A
	int score;
	//���O
	char name[15];
	//���O���͐�
	int name_num;
	//�J�[�\��X���W
	int cursor_x;
	//�J�[�\��Y���W
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
	//���O���͏���
	bool InputName();
};