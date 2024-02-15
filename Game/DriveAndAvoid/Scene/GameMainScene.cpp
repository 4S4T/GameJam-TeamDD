#include"GameMainScene.h"
#include"../Object/RankingData.h"
#include "../Utility/InputControl.h"
#include"DxLib.h"
#include<math.h>

GameMainScene::GameMainScene() : high_score(0), back_ground(NULL), barrier_image(NULL), mileage(0), player(nullptr)
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
	
	//�����̓Ǎ�
	kira = LoadSoundMem("Resource/sounds/kira.mp3");
	ChangeVolumeSoundMem(250, kira);
	bisi = LoadSoundMem("Resource/sounds/bisi.mp3");
	BGM = LoadSoundMem("Resource/sounds/Relay.mp3");
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���\n");
	}

	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.png������܂���\n");
	}

	//�I�u�W�F�N�g�̐���
	player = new Player;
	//item_base = new Item_Base * [8];
	//item = new Item * [10];

	//�I�u�W�F�N�g�̏�����
	player->Initialize();

	item_spawn_max = 0;
	item_spawn_rate = 0;

	YagiFlg = FALSE;
}

//�X�V����
eSceneType GameMainScene::Update()
{
	if (Matatabi_Flg == TRUE) {
		if (++Matatabi_cnt >= Matatabi_Time) {
			Matatabi_Flg = FALSE;
		}
	}

	if (YagiFlg == FALSE)
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

		if (++item_spawn_rate >= item_spawn_max)
		{
			int j = GetRand(8);
			bool seted_lane[5] = { FALSE };
			for (int i = 0; i < j; i++)
			{
				if (item_base[i] == nullptr)
				{
					int type;
					int percent = GetRand(99) + 1;
					if (Matatabi_Flg != TRUE)
					{
						if (percent <= 30)
						{
							type = 0;
						}
						else if (percent > 30 && percent <= 60)
						{
							type = 1;
						}
						else if (percent > 60 && percent <= 75)
						{
							type = 2;
						}
						else if (percent > 75 && percent <= 90)
						{
							type = 3;
						}
						else if (percent > 90 && percent <= 95)
						{
							type = 4;
						}
						else if (percent > 95 && percent <= 100)
						{
							type = 5;
						}
					}
					else
					{
						if (percent <= 70)
						{
							type = 0;
						}
						else if (percent > 70 && percent <= 100)
						{
							type = 2;
						}
					}
					int set_lane = GetRand(4);
					if (seted_lane[set_lane] == FALSE)
					{
						switch (type)
						{
						case 0:
							item_base[i] = new Item(type);
							item_base[i]->Initialize(set_lane);
							break;
						case 1:
							item_base[i] = new Enemy1(type);
							item_base[i]->Initialize(set_lane);
							break;
						case 2:
							item_base[i] = new Item2(type);
							item_base[i]->Initialize(set_lane);
							break;
						case 3:
							item_base[i] = new Enemy2(type);
							item_base[i]->Initialize(set_lane);
							break;
						case 4:
							item_base[i] = new Item3(type);
							item_base[i]->Initialize(set_lane);
							break;
						case 5:
							item_base[i] = new Enemy3(type);
							item_base[i]->Initialize(set_lane);
							break;
						default:
							break;
						}
						seted_lane[set_lane] = TRUE;
					}
				}
			}
			item_spawn_max = GetRand(60) + 120;
		}
		for (int i = 0; i < 8; i++)
		{
			if (item_base[i] != nullptr) {
				item_base[i]->Update(player->GetSpeed());

				//��ʊO�ɂ�������A�G���폜���ăX�R�A���Z
				if (item_base[i]->GetLocation().x <= 0.0f)
				{
					item_base[i]->Finalize();
					delete item_base[i];
					item_base[i] = nullptr;
				}

				//�����蔻��̊m�F
				if (IsHitItem(player, item_base[i]))
				{
					//�_���[�W����
					if (item_base[i]->GetType() == 0)
					{
						player->DecreaseHp(50.0f);
						PlaySoundMem(kira, DX_PLAYTYPE_BACK);
					}
					if (item_base[i]->GetType() == 1)
					{
						player->DecreaseHp(-50.0f);
						PlaySoundMem(bisi, DX_PLAYTYPE_BACK);
					}
					if (item_base[i]->GetType() == 2)
					{
						player->DecreaseHp(100.0f);
						PlaySoundMem(kira, DX_PLAYTYPE_BACK);
					}
					if (item_base[i]->GetType() == 3)
					{
						player->DecreaseHp(-100.0f);
						PlaySoundMem(bisi, DX_PLAYTYPE_BACK);
					}
					if (item_base[i]->GetType() == 4)
					{
						Matatabi_Flg = TRUE;
						Matatabi_cnt = 0;
						Matatabi_Time = 300;
						PlaySoundMem(kira, DX_PLAYTYPE_BACK);
					}
					if (item_base[i]->GetType() == 5)
					{
						YagiFlg = TRUE;
						YagiWaitTime = 3;
					}
					item_base[i]->Finalize();
					delete item_base[i];
					item_base[i] = nullptr;
				}
			}
		}
	}
	else 
	{
		// ���M�ɓ���������
		++YagiFps;
		player->DecreaseHp(-1.0f);
		if (YagiFps >= 60 * YagiWaitTime)
		{
			YagiFlg = FALSE;
			YagiFps = 0;

		}
	}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_Y))
	{
		//return eSceneType::E_RANKING_INPUT;
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
	for (int i = 0; i < 7; i++)
	{
		if (item_base[i] != nullptr)
		{
			item_base[i]->Draw();
		}
	}
	//�G�ƃA�C�e���̕`��

	//�v���C���[�̕`��
	player->Draw();

	//UI�̕`��
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0 ), "�n�C�X�R�A");
	DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);

	DrawFormatString(510, 800, GetColor(0, 0, 0), "����������");
	DrawFormatString(555, 100, GetColor(255, 255, 255), "%8d", mileage / 10);
	DrawFormatString(510, 120, GetColor(0, 0, 0), "�X�s�[�h");
	DrawFormatString(555, 140, GetColor(255, 255, 255), "%08.1f", player->GetSpeed());

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

	for (int i = 0; i < 8; i++)
	{
		if (item_base[i] != nullptr)
		{
			item_base[i]->Finalize();
			delete item_base[i];
			item_base[i] = nullptr;
		}
	}

	DeleteSoundMem (BGM);
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

bool GameMainScene::IsHitItem(Player* p, Item_Base* i)
{
 //�v���C���[���o���A���͂��Ă�����A�����蔻��𖳎�����
if (p->IsBarrier())
{
	return false;
}

//�G��񂪂Ȃ���΁A�����蔻��𖳎�����
if (i == nullptr)
{
	return false;
}

//�ʒu���̍������擾
Vector2D diff_location = p->GetLocation() - i->GetLocation();

//�����蔻��T�C�Y�̑傫�����擾
Vector2D box_ex = p->GetBoxSize() + i->GetBoxSize();

//�R���W�����f�[�^���ʒu���̍������������Ȃ�A�q�b�g����Ƃ���
return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}
