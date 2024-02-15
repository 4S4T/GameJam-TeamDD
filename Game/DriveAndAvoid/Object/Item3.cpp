#include "Item3.h"
#include "DxLib.h"

Item3::Item3(int type) : type(type), image(), speed(0.0f), location(0.0f), box_size(0.0f)
{

}

Item3::~Item3()
{

}

//����������
void Item3::Initialize()
{

	image = LoadGraph("Resource/images/matatabi.png", image);

	//�o��������X���W�p�^�[���擾
	float random_y = (float)(GetRand(4) * 60 + (GetRand(150) + 70));

	//�����ʒu�̐ݒ�
	location = Vector2D(550.0f, random_y);

	//�����蔻��̐ݒ�
	box_size = Vector2D(31.0f, 60.0f);

	//�����̐ݒ�
	speed = 1.0f; //(float)(this->type * 2);
}

void Item3::Update(float speed)
{

	//�ʒu���Ɉړ��ʂ����Z����
	location -= Vector2D(this->speed + speed, 0.0f);// + speed - 6);

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