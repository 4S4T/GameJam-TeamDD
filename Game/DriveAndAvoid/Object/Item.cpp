#include "Item.h"
#include "DxLib.h"

Item::Item(int type) : Item_Base(type)
{

}

Item::~Item()
{

}

//����������
void Item::Initialize(int set_lane)
{

	image = LoadGraph("Resource/images/car.png", image);

	//�o��������X���W�p�^�[���擾
	float random_y = (float)(set_lane * 60 + 170);

	//�����ʒu�̐ݒ�
	location = Vector2D(550.0f, random_y);

	//�����蔻��̐ݒ�
	box_size = Vector2D(30.0f, 30.0f);

	//�����̐ݒ�
	speed = 1.0f; //(float)(this->type * 2);
}
void Item::Draw() const
{

	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Item::Finalize()
{

}

//�G�̃^�C�v���擾
int Item::GetType() const
{

	return type;

}

//�ʒu�����擾
Vector2D Item::GetLocation()const
{

	return location;

}

//�����蔻��̑傫���擾
Vector2D Item::GetBoxSize() const
{
	return box_size;
}