#include "Item2.h"
#include "DxLib.h"

Item2::Item2(int type) : Item_Base(type)
{
	
}

Item2::~Item2()
{

}

//����������
void Item2::Initialize()
{

	image = LoadGraph("Resource/images/food_maguro_saku2.png", image);

	//�o��������X���W�p�^�[���擾
	float random_y = (float)(GetRand(4) * 60 + 170);

	//�����ʒu�̐ݒ�
	location = Vector2D(550.0f, random_y);

	//�����蔻��̐ݒ�
	box_size = Vector2D(30.0f, 30.0f);

	//�����̐ݒ�
	speed = 4.0f; //(float)(this->type * 2);
}

void Item2::Draw() const
{

	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Item2::Finalize()
{

}

//�G�̃^�C�v���擾
int Item2::GetType() const
{

	return type;

}

//�ʒu�����擾
Vector2D Item2::GetLocation()const
{

	return location;

}

//�����蔻��̑傫���擾
Vector2D Item2::GetBoxSize() const
{
	return box_size;
}