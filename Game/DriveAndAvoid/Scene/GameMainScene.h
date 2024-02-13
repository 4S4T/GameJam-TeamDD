#pragma once

#include"SceneBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"

class GameMainScene :public SceneBase
{

private:

	//�n�C�X�R�A
	int high_score;
	//�w�i�摜
	int back_ground;
	//�o���A�摜
	int barrier_image;
	//���s����
	int mileage;
	//�G�摜
	int enemy_image[3];
	int Enemy_image[6];
	//�ʂ�߂����GCOUNT
	int enemy_count[3];
	//�v���C���[
	Player* player;
	//�G
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

	//�n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();
	//�����蔻��
	bool IsHitCheck(Player* p, Enemy* e);
};