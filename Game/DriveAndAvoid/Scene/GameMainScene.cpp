#include"GameMainScene.h"
#include"../Object/RankingData.h"
#include"DxLib.h"
#include<math.h>

GameMainScene::GameMainScene() : high_score(0), back_ground(NULL), barrier_image(NULL), mileage(0), player(nullptr),
enemy(nullptr), item(nullptr),item2(nullptr),enemy1(nullptr),enemy2(nullptr),enemy3(nullptr)
{
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

GameMainScene::~GameMainScene()
{

}

//����������
void GameMainScene::Initialize()
{
	//�����_�l��ǂݍ���
	ReadHighScore();

	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/images/BackScroll_Image.png");
	barrier_image = LoadGraph("Resource/images/barrier.png");

	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���\n");
	}

	//if (result == -1)
	//{
	//	throw("Resource/images/car.bmp������܂���\n");
	//}

	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.png������܂���\n");
	}

	//�I�u�W�F�N�g�̐���
	player = new Player;
	enemy = new Enemy * [5];
	//item = new Item * [10];
	item = new Item(0);
	item2 = new Item2(0);
	enemy1 = new Enemy1(0);
	enemy2 = new Enemy2(0);

	//�I�u�W�F�N�g�̏�����
	player->Initialize();

	for (int i = 0; i < 5; i++)
	{
		enemy[i] = nullptr;
	}

	for (int i = 0; i < 10; i++)
	{
		item = nullptr;
	}
	for (int i = 0; i < 10; i++)
	{
		item2 = nullptr;
	}

	for (int i = 0; i < 5; i++)
	{
		enemy1 = nullptr;
	}
	for (int i = 0; i < 5; i++)
	{
		enemy2 = nullptr;
	}
}

//�X�V����
eSceneType GameMainScene::Update()
{
	//�v���C���[�̍X�V
	player->Update();

	//�ړ������̍X�V
	mileage += (int)player->GetSpeed() + 5;

	if (++flame >= 60) {
		second++;
		flame = 0;
		if (second % 5 == 0) {
			player->Acceleration();
			second = 0;
		}
	}

	

	//�G�������� //�A�C�e����������
	if (mileage / 20 % 100 == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (enemy[i] == nullptr)
			{
				int type = GetRand(1) % 1;
				enemy[i] = new Enemy(type, enemy_image[type]);
				enemy[i]->Initialize();
				break;
			}
			if (enemy[i] == nullptr)
			{
				int type = GetRand(2) % 2;
				enemy[i] = new Enemy(type, enemy_image[type]);
				enemy[i]->Initialize();
				break;
			}
		}
		/*
		for (int i = 0; i < 10; i++)
		{
			if (item == nullptr)
			{
				int type = item_image;
				item = new Item(item_image);
				item->Initialize();
				break;
			}
		}
		*/
	}

	if (mileage / 20 % 100 == 0)
	{
			if (item == nullptr)
			{
				item = new Item(0);
				item->Initialize();
				
			}
	}

	if (mileage / 20 % 100 == 0)
	{

		if (item2 == nullptr)
		{
			
			item2 = new Item2(0);
			item2->Initialize();

		}
	}

	if (mileage / 20 % 100 == 0)
	{

		if (enemy1 == nullptr)
		{

			enemy1 = new Enemy1(0);
			enemy1->Initialize();

		}
	}

	if (mileage / 20 % 100 == 0)
	{

		if (enemy2 == nullptr)
		{

			enemy2 = new Enemy2(0);
			enemy2->Initialize();

		}
	}

	if (mileage / 20 % 100 == 0)
	{

		if (enemy3 == nullptr)
		{

			enemy3 = new Enemy3(0);
			enemy3->Initialize();

		}
	}
	//�G�̍X�V�Ɠ����蔻��`�F�b�N
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update(player->GetSpeed());

			//��ʊO�ɂ�������A�G���폜���ăX�R�A���Z
			if (enemy[i]->GetLocation().y >= 640.0f)
			{
				enemy_count[enemy[i]->GetType()]++;
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}

			//�����蔻��̊m�F
			if (IsHitCheck(player, enemy[i]))
			{
				player->SetActive(false);

				//�_���[�W����
				player->DecreaseHp(-50.0f);
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}
		}
	}

	//�A�C�e���̍X�V�Ɣ���`�F�b�N
	if (item != nullptr)
	{
		item->Update(player->GetSpeed());
		if (item->GetLocation().x <= 0.0f)
		{
			item->Finalize();
			delete item;
			item = nullptr;
		}
		//�����蔻��̊m�F
		if (IsHitCheck2(player, item))
		{
			player->SetActive(true);

			//�_���[�W����
			player->DecreaseHp(+50.0f);
			item->Finalize();
			delete item;
			item = nullptr;
		}
	}

	if (item2 != nullptr)
	{
		item2->Update(player->GetSpeed());
		if (item2->GetLocation().y >= 640.0f)
		{
			item2->Finalize();
			delete item2;
			item2 = nullptr;
		}
		//�����蔻��̊m�F
		if (IsHitCheck3(player, item2))
		{
			player->SetActive(true);

			//�_���[�W����
			player->DecreaseHp(+200.0f);
			item2->Finalize();
			delete item2;
			item2 = nullptr;
		}
	}

	//�����݂̍X�V�Ɠ����蔻��`�F�b�N
	if (enemy1 != nullptr)
	{
		enemy1->Update(player->GetSpeed());
		if (enemy1->GetLocation().y >= 640.0f)
		{
			enemy1->Finalize();
			delete enemy1;
			enemy1 = nullptr;
		}
		//�����蔻��̊m�F
		if (IsHitCheck4(player, enemy1))
		{
			player->SetActive(true);

			//�_���[�W����
			player->DecreaseHp(-100.0f);
			enemy1->Finalize();
			delete enemy1;
			enemy1 = nullptr;
		}
	}

	if (enemy2 != nullptr)
	{
		enemy2->Update(player->GetSpeed());
		if (enemy2->GetLocation().y >= 640.0f)
		{
			enemy2->Finalize();
			delete enemy2;
			enemy2 = nullptr;
		}
		//�����蔻��̊m�F
		if (IsHitCheck5(player, enemy2))
		{
			player->SetActive(true);

			//�_���[�W����
			player->DecreaseHp(-100.0f);
			enemy2->Finalize();
			delete enemy2;
			enemy2 = nullptr;
		}
	}

	if (enemy3 != nullptr)
	{
		enemy3->Update(player->GetSpeed());
		if (enemy3->GetLocation().y >= 640.0f)
		{
			enemy3->Finalize();
			delete enemy3;
			enemy3= nullptr;
		}
		//�����蔻��̊m�F
		if (IsHitCheck6(player, enemy3))
		{
			player->SetActive(true);

			//�_���[�W����
			player->DecreaseHp(-100.0f);
			enemy3->Finalize();
			delete enemy3;
			enemy3 = nullptr;
		}
	}
	//�v���C���[�̔R�����̗͂�0�����Ȃ�A���U���g�ɑJ�ڂ���
	if (player->GetHp() < 0.0f)
	{
		return eSceneType::E_RESULT;
	}
	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw()const
{
	//�w�i�摜�̕`��
	DrawGraph(1600 - (mileage % 1600) - 1600, 0, back_ground, TRUE);
	DrawGraph(1600 - (mileage % 1600), 0, back_ground, TRUE);

	//�G�̕`��
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

		if (item != nullptr)
		{
			item->Draw();
		}
	
		if (item2 != nullptr)
		{
			item2->Draw();
		}

		if (enemy1 != nullptr)
		{
			enemy1->Draw();
		}

		if (enemy2 != nullptr)
		{
			enemy2->Draw();
		}

		if (enemy3 != nullptr)
		{
			enemy3->Draw();
		}

	//�v���C���[�̕`��
	player->Draw();

	//UI�̕`��
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0 ), "�n�C�X�R�A");
	DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);
	DrawFormatString(510, 80, GetColor(0, 0, 0), "��������");

	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, enemy_image[i], TRUE, FALSE);
		DrawFormatString(510 + (i * 50), 140, GetColor(255, 255, 255), "%03d", enemy_count[i]);

	}

	DrawFormatString(510, 200, GetColor(0, 0, 0), "���s����");
	DrawFormatString(555, 220, GetColor(255, 255, 255), "%8d", mileage / 10);
	DrawFormatString(510, 240, GetColor(0, 0, 0), "�X�s�[�h");
	DrawFormatString(555, 260, GetColor(255, 255, 255), "%08.1f", player->GetSpeed());

	//�o���A�����̕`��
	for (int i = 0; i < player->GetBarriarCount(); i++)
	{
		DrawRotaGraph(520 + i * 25, 340, 0.2f, 0, barrier_image, TRUE, FALSE);
	}

	//�̗̓Q�[�W�̕`��
	float fx = 510.0f;
	float fy = 430.0f;
	DrawFormatStringF(fx, fy, GetColor(0, 0, 0), "�H���Q�[�W");
	DrawBoxAA(fx, fy + 20.0f, fx + (player->GetHp() * 100 / 1000), fy + 40.0f, GetColor(255, 182, 0), TRUE);
	DrawBoxAA(fx, fy + 20.0f, fx + 100.0f, fy + 40.0f, GetColor(0, 0, 0), FALSE);
}

//�I��������
void GameMainScene::Finalize()
{
	//�X�R�A�����Z����
	int score = (mileage / 10 * 10);
	for (int i = 0; i < 3; i++)
	{
		score += (i + 1) * 50 * enemy_count[i];
	}

	//���U���g�f�[�^�̏�������
	FILE* fp = nullptr;

	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "w");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/result_data.csv���J���܂���\n");
	}

	//�X�R�A��ۑ�
	fprintf(fp, "%d,\n", score);

	fprintf(fp, "%d,\n", mileage);

	//���������Ɠ��_��ۑ�
	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "%d,\n", enemy_count[i]);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	//���I�m�ۂ����I�u�W�F�N�g���폜����
	player->Finalize();
	delete player;

	for (int i = 0; i < 5; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Finalize();
			delete enemy[i];
			enemy[i] = nullptr;
		}
	}

	delete[] enemy;
	delete item;
	delete item2;
}

//���݂̃V�[�������擾
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

//�n�C�X�R�A�̓ǂݍ���
void GameMainScene::ReadHighScore()
{
	RankingData data;
	data.Initialize();

	high_score = data.GetScore(0);

	data.Finlize();
}

//�����蔻�菈���i�v���C���[�ƓG�j
bool GameMainScene::IsHitCheck(Player* p, Enemy* e)
{
	//�v���C���[���o���A���͂��Ă�����A�����蔻��𖳎�����
	if (p->IsBarrier())
	{
		return false;
	}

	//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (e == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - e->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::IsHitCheck2(Player* p, Item* i)
{
	//�v���C���[���o���A���͂��Ă�����A�����蔻��𖳎�����
	/*if (p->IsBarrier())
	{
		return false;
	}*/

	//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (i == nullptr)
	{
		return true;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - i->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + i->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}



bool GameMainScene::IsHitCheck3(Player* p, Item2*i2)
{
	//�v���C���[���o���A���͂��Ă�����A�����蔻��𖳎�����
	if (p->IsBarrier())
	{
		return false;
	}

	//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (i2 == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - i2->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + i2->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}
bool GameMainScene::IsHitCheck4(Player* p, Enemy1*e1)
{
	//�v���C���[���o���A���͂��Ă�����A�����蔻��𖳎�����
	if (p->IsBarrier())
	{
		return false;
	}

	//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (e1 == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - e1->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + e1->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::IsHitCheck5(Player* p, Enemy2* e2)
{
	//�v���C���[���o���A���͂��Ă�����A�����蔻��𖳎�����
	if (p->IsBarrier())
	{
		return false;
	}

	//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (e2 == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - e2->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + e2->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::IsHitCheck6(Player* p, Enemy3* e3)
{
	//�v���C���[���o���A���͂��Ă�����A�����蔻��𖳎�����
	if (p->IsBarrier())
	{
		return false;
	}

	//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
	if (e3 == nullptr)
	{
		return false;
	}

	//�ʒu���̍������擾
	Vector2D diff_location = p->GetLocation() - e3->GetLocation();

	//�����蔻��T�C�Y�̑傫�����擾
	Vector2D box_ex = p->GetBoxSize() + e3->GetBoxSize();

	//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}