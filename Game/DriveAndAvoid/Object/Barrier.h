#pragma once

#include"../Utility/Vector2D.h"

class Barrier
{
private:
	int count;
	//バリア画像
	int image[6];

	//バリアの寿命
	float life_span;

public:
	Barrier();
	~Barrier();

	//画像処理
	void Draw(const Vector2D& location);

	//寿命が尽きたか？
	bool IsFinished(float speed);
};