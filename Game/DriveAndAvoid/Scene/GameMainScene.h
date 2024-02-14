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
	//�ʂ�߂����GCOUNT
	int enemy_count[3];
	//�v���C���[
	Player* player;
	//�G
	Enemy** enemy;

	//�A�C�e��
	Item* item;
	Item2* item2;
	Enemy1* enemy1;
	Enemy2* enemy2;
	Enemy3* enemy3;

	int flame;
	int second;
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
	bool IsHitCheck2(Player* p, Item* i);
	bool IsHitCheck3(Player* p, Item2* i2);
	bool IsHitCheck4(Player* p, Enemy1* e1);
	bool IsHitCheck5(Player* p, Enemy2* e2);
	bool IsHitCheck6(Player* p, Enemy3* e3);
};