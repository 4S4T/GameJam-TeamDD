#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL), cursor_image(NULL), 
start_btn(NULL),rank_btn(NULL),end_btn(NULL),menu_cursor(NULL), cursorSE(NULL),ketteiSE(NULL),BGM(NULL),
font1(0)
{

}

TitleScene::~TitleScene()
{

}

//初期化処理
void TitleScene::Initialize()
{
	//画像の読み込み
	background_image = LoadGraph("Resource/images/road_backimage.png");
	start_btn = LoadGraph("Resource/images/start_BTN.png");
	rank_btn  = LoadGraph("Resource/images/rank_BTN.png");
	end_btn	  = LoadGraph("Resource/images/end_BTN.png");
	cursor_image = LoadGraph("Resource/images/cat_hand.png");
	font1 = CreateFontToHandle("Elephant", 60, 8, DX_FONTTYPE_ANTIALIASING_EDGE);

	//エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmpがありません/n");
	}
	if (menu_image == -1)
	{
		throw("Resource/images/menu.bmpがありません/n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmpがありません/n");
	}
	// 音声の読込
	cursorSE = LoadSoundMem("Resource/sounds/pi.mp3");
	//ChangeVolumeSoundMem(250, kira);
	ketteiSE = LoadSoundMem("Resource/sounds/pinn.mp3");
	BGM = LoadSoundMem("Resource/sounds/titleBGM.mp3");
	PlaySoundMem(BGM, DX_PLAYTYPE_BACK);
}

//更新処理
eSceneType TitleScene::Update()
{
	//カーソル下移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		//一番下に到達したら、一番上にする
		if (menu_cursor > 2)
		{
			menu_cursor = 0;
		}
	}

	//カーソル上移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		//一番上に到達したら、一番下にする
		if (menu_cursor < 0)
		{
			menu_cursor = 2;
		}
	}

	//カーソル決定（決定した画面に遷移する）
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A))
	{
		
		PlaySoundMem(ketteiSE, DX_PLAYTYPE_BACK);
		
		switch (menu_cursor)
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_RANKING_DISP;
		/*case 2:
			return eSceneType::E_HELP;*/
		default:
			return eSceneType::E_END;

		}
		
	}

	//現在のシーンタイプを返す
	return GetNowScene();
}
 
//描画処理
void TitleScene::Draw() const
{
	//タイトル画像の描画
	DrawGraph(0, 0, background_image, FALSE);
	//メニュー画像の描画
	DrawGraph(120, 200, menu_image, TRUE);

	DrawGraph(400, 270, start_btn, TRUE);
	DrawGraph(400, 340, rank_btn, TRUE);
	DrawGraph(400, 410, end_btn, TRUE);
	
	//カーソル画像の描画
	DrawRotaGraph(360, 300 + menu_cursor * 70, 0.8, 0, cursor_image, TRUE);

	DrawStringToHandle(150, 100, "Getyu~ru", 0xffec47, font1);

}

//終了時処理
void TitleScene::Finalize()
{
	//読み込んだ画像の削除
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(start_btn);
	DeleteGraph(rank_btn);
	DeleteGraph(end_btn);
	DeleteGraph(cursor_image);
	
	DeleteSoundMem(BGM);
}

//現在のシーン情報を取得
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}