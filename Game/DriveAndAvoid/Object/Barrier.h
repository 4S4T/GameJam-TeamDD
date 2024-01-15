#pragma once

#include"../Utility/Vector2D.h"

class Barrier
{
private:

	//�o���A�摜
	int image;

	//�o���A�̎���
	float life_span;

public:
	Barrier();
	~Barrier();

	//�摜����
	void Draw(const Vector2D& location);

	//�������s�������H
	bool IsFinished(float speed);
};