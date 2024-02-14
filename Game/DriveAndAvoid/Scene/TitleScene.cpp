#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

TitleScene::TitleScene() : background_image(NULL), menu_image(NULL), cursor_image(NULL), menu_cursor(0)
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
	menu_image = LoadGraph("Resource/images/menu.bmp");
	menu_image = LoadDivGraph ("Resource/images/menu.bmp",4,1,4,195,40,gMenu);
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
}

//�X�V����
eSceneType TitleScene::Update()
{
	//�J�[�\�����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;

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

		//��ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 2;
		}
	}

	//�J�[�\������i���肵����ʂɑJ�ڂ���j
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
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

	DrawGraph(140, 300, gMenu[0], TRUE);
	DrawGraph(140, 340, gMenu[1], TRUE);
	DrawGraph(140, 380, gMenu[3], TRUE);

	//�J�[�\���摜�̕`��
	DrawRotaGraph(100, 320 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image, TRUE);

	DrawStringToHandle(150, 100, "Getyu~ru", 0xffec47, font1);
}

//�I��������
void TitleScene::Finalize()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(gMenu[0]);
	DeleteGraph(gMenu[1]);
	DeleteGraph(gMenu[2]);
	DeleteGraph(gMenu[3]);
	DeleteGraph(cursor_image);
}

//���݂̃V�[�������擾
eSceneType TitleScene::GetNowScene() const
{
	return eSceneType::E_TITLE;
}