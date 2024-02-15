#include "Enemy3.h"
#include "DxLib.h"

Enemy3::Enemy3(int type) : Item_Base(type)
{

}

Enemy3::~Enemy3()
{

}

//����������
void Enemy3::Initialize()
{

	image = LoadGraph("Resource/images/unscreen-001.png", image);

	//�o��������X���W�p�^�[���擾
	float random_y = (float)(GetRand(4) * 60 + 170);

	//�����ʒu�̐ݒ�
	location = Vector2D(550.0f, random_y);

	//�����蔻��̐ݒ�
	box_size = Vector2D(30.0f, 30.0f);

	//�����̐ݒ�
	speed = 1.8f; //(float)(this->type * 2);
}

void Enemy3::Draw() const
{

	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Enemy3::Finalize()
{

}

//�G�̃^�C�v���擾
int Enemy3::GetType() const
{

	return type;

}

//�ʒu�����擾
Vector2D Enemy3::GetLocation()const
{

	return location;

}

//�����蔻��̑傫���擾
Vector2D Enemy3::GetBoxSize() const
{
	return box_size;
}