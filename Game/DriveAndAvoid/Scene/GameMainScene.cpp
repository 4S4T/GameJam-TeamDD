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

//初期化処理
void GameMainScene::Initialize()
{
	//高得点値を読み込む
	ReadHighScore();

	//画像の読み込み
	back_ground = LoadGraph("Resource/images/BackScroll_Image.png");
	barrier_image = LoadGraph("Resource/images/barrier.png");
	

	//エラーチェック
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmpがありません\n");
	}

	//if (result == -1)
	//{
	//	throw("Resource/images/car.bmpがありません\n");
	//}

	if (barrier_image == -1)
	{
		throw("Resource/images/barrier.pngがありません\n");
	}

	//オブジェクトの生成
	player = new Player;
	enemy = new Enemy * [5];
	//item = new Item * [10];
	item = new Item(0);
	item2 = new Item2(0);
	enemy1 = new Enemy1(0);
	enemy2 = new Enemy2(0);

	//オブジェクトの初期化
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

//更新処理
eSceneType GameMainScene::Update()
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

	

	//敵生成処理 //アイテム生成処理
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
	//敵の更新と当たり判定チェック
	for (int i = 0; i < 5; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update(player->GetSpeed());

			//画面外にいったら、敵を削除してスコア加算
			if (enemy[i]->GetLocation().y >= 640.0f)
			{
				enemy_count[enemy[i]->GetType()]++;
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}

			//当たり判定の確認
			if (IsHitCheck(player, enemy[i]))
			{
				player->SetActive(false);

				//ダメージ処理
				player->DecreaseHp(-50.0f);
				enemy[i]->Finalize();
				delete enemy[i];
				enemy[i] = nullptr;
			}
		}
	}

	//アイテムの更新と判定チェック
	if (item != nullptr)
	{
		item->Update(player->GetSpeed());
		if (item->GetLocation().x <= 0.0f)
		{
			item->Finalize();
			delete item;
			item = nullptr;
		}
		//当たり判定の確認
		if (IsHitCheck2(player, item))
		{
			player->SetActive(true);

			//ダメージ処理
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
		//当たり判定の確認
		if (IsHitCheck3(player, item2))
		{
			player->SetActive(true);

			//ダメージ処理
			player->DecreaseHp(+200.0f);
			item2->Finalize();
			delete item2;
			item2 = nullptr;
		}
	}

	//生ごみの更新と当たり判定チェック
	if (enemy1 != nullptr)
	{
		enemy1->Update(player->GetSpeed());
		if (enemy1->GetLocation().y >= 640.0f)
		{
			enemy1->Finalize();
			delete enemy1;
			enemy1 = nullptr;
		}
		//当たり判定の確認
		if (IsHitCheck4(player, enemy1))
		{
			player->SetActive(true);

			//ダメージ処理
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
		//当たり判定の確認
		if (IsHitCheck5(player, enemy2))
		{
			player->SetActive(true);

			//ダメージ処理
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
		//当たり判定の確認
		if (IsHitCheck6(player, enemy3))
		{
			player->SetActive(true);

			//ダメージ処理
			player->DecreaseHp(-100.0f);
			enemy3->Finalize();
			delete enemy3;
			enemy3 = nullptr;
		}
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

	//プレイヤーの描画
	player->Draw();

	//UIの描画
	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);
	SetFontSize(16);
	DrawFormatString(510, 20, GetColor(0, 0, 0 ), "ハイスコア");
	DrawFormatString(560, 40, GetColor(255, 255, 255), "%08d", high_score);
	DrawFormatString(510, 80, GetColor(0, 0, 0), "避けた数");

	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(523 + (i * 50), 120, 0.3, 0, enemy_image[i], TRUE, FALSE);
		DrawFormatString(510 + (i * 50), 140, GetColor(255, 255, 255), "%03d", enemy_count[i]);

	}

	DrawFormatString(510, 200, GetColor(0, 0, 0), "走行距離");
	DrawFormatString(555, 220, GetColor(255, 255, 255), "%8d", mileage / 10);
	DrawFormatString(510, 240, GetColor(0, 0, 0), "スピード");
	DrawFormatString(555, 260, GetColor(255, 255, 255), "%08.1f", player->GetSpeed());

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

//当たり判定処理（プレイヤーと敵）
bool GameMainScene::IsHitCheck(Player* p, Enemy* e)
{
	//プレイヤーがバリアをはっていたら、当たり判定を無視する
	if (p->IsBarrier())
	{
		return false;
	}

	//敵情報がなければ、当たり判定を無視する
	if (e == nullptr)
	{
		return false;
	}

	//位置情報の差分を取得
	Vector2D diff_location = p->GetLocation() - e->GetLocation();

	//当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + e->GetBoxSize();

	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::IsHitCheck2(Player* p, Item* i)
{
	//プレイヤーがバリアをはっていたら、当たり判定を無視する
	/*if (p->IsBarrier())
	{
		return false;
	}*/

	//敵情報がなければ、当たり判定を無視する
	if (i == nullptr)
	{
		return true;
	}

	//位置情報の差分を取得
	Vector2D diff_location = p->GetLocation() - i->GetLocation();

	//当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + i->GetBoxSize();

	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}



bool GameMainScene::IsHitCheck3(Player* p, Item2*i2)
{
	//プレイヤーがバリアをはっていたら、当たり判定を無視する
	if (p->IsBarrier())
	{
		return false;
	}

	//敵情報がなければ、当たり判定を無視する
	if (i2 == nullptr)
	{
		return false;
	}

	//位置情報の差分を取得
	Vector2D diff_location = p->GetLocation() - i2->GetLocation();

	//当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + i2->GetBoxSize();

	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}
bool GameMainScene::IsHitCheck4(Player* p, Enemy1*e1)
{
	//プレイヤーがバリアをはっていたら、当たり判定を無視する
	if (p->IsBarrier())
	{
		return false;
	}

	//敵情報がなければ、当たり判定を無視する
	if (e1 == nullptr)
	{
		return false;
	}

	//位置情報の差分を取得
	Vector2D diff_location = p->GetLocation() - e1->GetLocation();

	//当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + e1->GetBoxSize();

	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::IsHitCheck5(Player* p, Enemy2* e2)
{
	//プレイヤーがバリアをはっていたら、当たり判定を無視する
	if (p->IsBarrier())
	{
		return false;
	}

	//敵情報がなければ、当たり判定を無視する
	if (e2 == nullptr)
	{
		return false;
	}

	//位置情報の差分を取得
	Vector2D diff_location = p->GetLocation() - e2->GetLocation();

	//当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + e2->GetBoxSize();

	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::IsHitCheck6(Player* p, Enemy3* e3)
{
	//プレイヤーがバリアをはっていたら、当たり判定を無視する
	if (p->IsBarrier())
	{
		return false;
	}

	//敵情報がなければ、当たり判定を無視する
	if (e3 == nullptr)
	{
		return false;
	}

	//位置情報の差分を取得
	Vector2D diff_location = p->GetLocation() - e3->GetLocation();

	//当たり判定サイズの大きさを取得
	Vector2D box_ex = p->GetBoxSize() + e3->GetBoxSize();

	//コリジョンデータより位置情報の差分が小さいなら、ヒット判定とする
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}