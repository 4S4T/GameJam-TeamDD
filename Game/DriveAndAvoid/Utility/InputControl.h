#pragma once

#include "Vector2D.h"


//���͊Ǘ��@�\
class InputControl
{
private:

	//���݃t���[�����͒l
	static bool now_button[16];
	//�ߋ��t���[�����͒l
	static bool old_button[16];
	//���E�g���K�[���͒l
	static float trigger[2];
	//���E�X�e�B�b�N���͒l
	static Vector2D stick[2];

public:

	//�X�V����
	static void Update();

	//���������Ă����
	static bool GetButton(int button);
	//�������u��
	static bool GetButtonDown(int button);
	//�������u��
	static bool GetButtonUp(int button);

	//���g���K�[
	static float GetLeftTriggger();
	//�E�g���K�[
	static float GetRightTrigger();

	//���X�e�B�b�N
	static Vector2D GetLeftStick();
	//�E�X�e�B�b�N
	static Vector2D GetRightStick();

private:

	//�{�^���z��͈̓`�F�b�N
	static bool CheckButtonRange(int button);
};