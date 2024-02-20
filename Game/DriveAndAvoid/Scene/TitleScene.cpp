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

//����������
void TitleScene::Initialize()
{
	//�摜�̓ǂݍ���
	background_image = LoadGraph("Resource/images/road_backimage.png");
	start_btn = LoadGraph("Resource/images/start_BTN.png");
	rank_btn  = LoadGraph("Resource/images/rank_BTN.png");
	end_btn	  = LoadGraph("Resource/images/end_BTN.png");
	cursor_image = LoadGraph("Resource/images/cat_hand.png");
	font1 = CreateFontToHandle("Elephant", 60, 8, DX_FONTTYPE_ANTIALIASING_EDGE);

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmp������܂���/n");
	}
	if (menu_image == -1)
	{
		throw("Resource/images/menu.bmp������܂���/n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmp������܂���/n");
	}
	// �����̓Ǎ�
	cursorSE = LoadSoundMem("Resource/sounds/pi.mp3");
	//ChangeVolumeSoundMem(250, kira);
	ketteiSE = LoadSoundMem("Resource/sounds/pinn.mp3");
	BGM = LoadSoundMem("Resource/sounds/titleBGM.mp3");
	PlaySoundMem(BGM, DX_PLAYTYPE_BACK);
}

//�X�V����
eSceneType TitleScene::Update()
{
	//�J�[�\�����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		//��ԉ��ɓ��B������A��ԏ�ɂ���
		if (menu_cursor > 2)
		{
			menu_cursor = 0;
		}
	}

	//�J�[�\����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		PlaySoundMem(cursorSE, DX_PLAYTYPE_BACK);
		//��ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 2;
		}
	}

	//�J�[�\������i���肵����ʂɑJ�ڂ���j
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

	//���݂̃V�[���^�C�v��Ԃ�
	return GetNowScene();
}
 
//�`�揈��
void TitleScene::Draw() const
{
	//�^�C�g���摜�̕`��
	DrawGraph(0, 0, background_image, FALSE);
	//���j���[�摜�̕`��
	DrawGraph(120, 200, menu_image, TRUE);

	DrawGraph(400, 270, start_btn, TRUE);
	DrawGraph(400, 340, rank_btn, TRUE);
	DrawGraph(400, 410, end_btn, TRUE);
	
	//�J�[�\���摜�̕`��
	DrawRotaGraph(360, 300 + menu_cursor * 70, 0.8, 0, cursor_image, TRUE);

	DrawStringToHandle(150, 100, "Getyu~ru", 0xffec47, font1);

}

//�I��������
void TitleScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(start_btn);
	DeleteGraph(rank_btn);
	DeleteGraph(end_btn);
	DeleteGraph(cursor_image);
	
	DeleteSoundMem(BGM);
}

//���݂̃V�[�������擾
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}