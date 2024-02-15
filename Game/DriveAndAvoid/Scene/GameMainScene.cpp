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

//初期化処理
void GameMainScene::Initialize()
{
	//高得点値を読み込む
	ReadHighScore();

	//画像の読み込み
	back_ground = LoadGraph("Resource/images/BackScroll_Image.png");
	barrier_image = LoadGraph("Resource/images/barrier.png");
	
	//音声の読込
	kira = LoadSoundMem("Resource/sounds/kira.mp3");
	ChangeVolumeSoundMem(250, kira);
	bisi = LoadSoundMem("Resource/sounds/bisi.mp3");
	BGM = LoadSoundMem("Resource/sounds/Relay.mp3");
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
	//エラーチェック
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmpがありません\n");
	}

	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.pngがありません\n");
	}

	//オブジェクトの生成
	player = new Player;
	//item_base = new Item_Base * [8];
	//item = new Item * [10];

	//オブジェクトの初期化
	player->Initialize();

	item_spawn_max = 0;
	item_spawn_rate = 0;

	YagiFlg = FALSE;
}

//更新処理
eSceneType GameMainScene::Update()
{
	if (Matatabi_Flg == TRUE) {
		if (++Matatabi_cnt >= Matatabi_Time) {
			Matatabi_Flg = FALSE;
		}
	}

	if (YagiFlg == FALSE)
	{


		//プレイヤーの更新
		player->Update();

		//移動距離の更新
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

				//画面外にいったら、敵を削除してスコア加算
				if (item_base[i]->GetLocation().x <= 0.0f)
				{
					item_base[i]->Finalize();
					delete item_base[i];
					item_base[i] = nullptr;
				}

				//当たり判定の確認
				if (IsHitItem(player, item_base[i]))
				{
					//ダメージ処理
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
		// ヤギに当たった際
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
	//プレイヤーの燃料か体力が0未満なら、リザルトに遷移する
	if (player->GetHp() < 0.0f)
	{
		return eSceneType::E_RESULT;
	}
	return GetNowScene();
}

//描画処理
void GameMainScene::Draw()const
{
	//背景画像の描画
	DrawGraph(1600 - (mileage % 1600) - 1600, 0, back_ground, TRUE);
	DrawGraph(1600 - (mileage % 1600), 0, back_ground, TRUE);

	//敵の描画
	for (int i = 0; i < 7; i++)
	{
		if (item_base[i] != nullptr)
		{
			item_base[i]->Draw();
		}
	}
	//敵とアイテムの描画

	//プレイヤーの描画
	player->Draw();

	//UIの描画
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0 ), "ハイスコア");
	DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);

	DrawFormatString(510, 800, GetColor(0, 0, 0), "走った距離");
	DrawFormatString(555, 100, GetColor(255, 255, 255), "%8d", mileage / 10);
	DrawFormatString(510, 120, GetColor(0, 0, 0), "スピード");
	DrawFormatString(555, 140, GetColor(255, 255, 255), "%08.1f", player->GetSpeed());

	//バリア枚数の描画
	for (int i = 0; i < player->GetBarriarCount(); i++)
	{
		DrawRotaGraph(520 + i * 25, 340, 0.2f, 0, barrier_image, TRUE, FALSE);
	}

	//体力ゲージの描画
	float fx = 510.0f;
	float fy = 430.0f;
	DrawFormatStringF(fx, fy, GetColor(0, 0, 0), "食料ゲージ");
	DrawBoxAA(fx, fy + 20.0f, fx + (player->GetHp() * 100 / 1000), fy + 40.0f, GetColor(255, 182, 0), TRUE);
	DrawBoxAA(fx, fy + 20.0f, fx + 100.0f, fy + 40.0f, GetColor(0, 0, 0), FALSE);
}

//終了時処理
void GameMainScene::Finalize()
{
	//スコアを加算する
	int score = (mileage / 10 * 10);
	for (int i = 0; i < 3; i++)
	{
		score += (i + 1) * 50 * enemy_count[i];
	}

	//リザルトデータの書き込み
	FILE* fp = nullptr;

	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "w");

	//エラーチェック
	if (result != 0)
	{
		throw("Resource/dat/result_data.csvが開けません\n");
	}

	//スコアを保存
	fprintf(fp, "%d,\n", score);

	fprintf(fp, "%d,\n", mileage);

	//避けた数と得点を保存
	for (int i = 0; i < 3; i++)
	{
		fprintf(fp, "%d,\n", enemy_count[i]);
	}

	//ファイルクローズ
	fclose(fp);

	//動的確保したオブジェクトを削除する
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

//現在のシーン情報を取得
eSceneType GameMainScene::GetNowScene() const
{
	return eSceneType::E_MAIN;
}

//ハイスコアの読み込み
void GameMainScene::ReadHighScore()
{
	RankingData data;
	data.Initialize();

	high_score = data.GetScore(0);

	data.Finlize();
}

bool GameMainScene::IsHitItem(Player* p, Item_Base* i)
{
 //プレイヤーがバリアをはっていたら、当たり判定を無視する
if (p->IsBarrier())
{
	return false;
}

//敵情報がなければ、当たり判定を無視する
if (i == nullptr)
{
	return false;
}

//位置情報の差分を取得
Vector2D diff_location = p->GetLocation() - i->GetLocation();

//当たり判定サイズの大きさを取得
Vector2D box_ex = p->GetBoxSize() + i->GetBoxSize();

//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}
