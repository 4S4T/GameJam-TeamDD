#pragma once

#include "Vector2D.h"


//入力管理機能
class InputControl
{
private:

	//現在フレーム入力値
	static bool now_button[16];
	//過去フレーム入力値
	static bool old_button[16];
	//左右トリガー入力値
	static float trigger[2];
	//左右スティック入力値
	static Vector2D stick[2];

public:

	//更新処理
	static void Update();

	//押し続けている間
	static bool GetButton(int button);
	//押した瞬間
	static bool GetButtonDown(int button);
	//離した瞬間
	static bool GetButtonUp(int button);

	//左トリガー
	static float GetLeftTriggger();
	//右トリガー
	static float GetRightTrigger();

	//左スティック
	static Vector2D GetLeftStick();
	//右スティック
	static Vector2D GetRightStick();

private:

	//ボタン配列範囲チェック
	static bool CheckButtonRange(int button);
};