#include "Item3.h"
#include "DxLib.h"

Item3::Item3(int type) : Item_Base(type)
{

}

Item3::~Item3()
{

}

//����������
void Item3::Initialize(int set_lane)
{

	image = LoadGraph("Resource/images/matatabi.png", image);

	//�o��������X���W�p�^�[���擾
	float random_y = (float)(set_lane * 60 + 170);

	//�����ʒu�̐ݒ�
	location = Vector2D(550.0f, random_y);

	//�����蔻��̐ݒ�
	box_size = Vector2D(30.0f, 30.0f);

	//�����̐ݒ�
	speed = 1.0f; //(float)(this->type * 2);
}

void Item3::Draw() const
{
    
	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Item3::Finalize()
{

}

//�G�̃^�C�v���擾
int Item3::GetType() const
{

	return type;

}

//�ʒu�����擾
Vector2D Item3::GetLocation()const
{

	return location;

}

//�����蔻��̑傫���擾
Vector2D Item3::GetBoxSize() const
{
	return box_size;
}