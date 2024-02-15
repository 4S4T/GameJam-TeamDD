#include "Enemy2.h"
#include "DxLib.h"

Enemy2::Enemy2(int type) : Item_Base(type)
{

}

Enemy2::~Enemy2()
{

}

//����������
void Enemy2::Initialize()
{

	image = LoadGraph("Resource/images/snake.png", image);

	//�o��������X���W�p�^�[���擾
	float random_y = (float)(GetRand(4) * 60 + 170);

	//�����ʒu�̐ݒ�
	location = Vector2D(550.0f,random_y);

	//�����蔻��̐ݒ�
	box_size = Vector2D(30.0f, 30.0f);

	//�����̐ݒ�
	speed = 2.0f; //(float)(this->type * 2);
}

void Enemy2::Draw() const
{
	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Enemy2::Finalize()
{

}

//�G�̃^�C�v���擾
int Enemy2::GetType() const
{

	return type;

}

//�ʒu�����擾
Vector2D Enemy2::GetLocation()const
{

	return location;

}

//�����蔻��̑傫���擾
Vector2D Enemy2::GetBoxSize() const
{
	return box_size;
}