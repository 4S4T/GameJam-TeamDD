#pragma once

#include "SceneBase.h"

class TitleScene : public SceneBase
{
private:

private:

	//�w�i�摜
	int background_image;
	//���j���[�摜
	int menu_image;
	//�J�[�\���摜
	int cursor_image;
	//���j���[�J�[�\���ԍ�
	int menu_cursor;

	int start_btn;
	int rank_btn;
	int end_btn;

	// �t�H���g
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