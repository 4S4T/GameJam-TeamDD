#include "Item2.h"
#include "DxLib.h"

Item2::Item2(int type) : type(type), image(), speed(0.0f), location(0.0f), box_size(0.0f)
{

}

Item2::~Item2()
{

}

//����������
void Item2::Initialize()
{

	//image = LoadGraph("Resource/images/car.png", image);

	//�o��������X���W�p�^�[���擾
	float random_x = (float)(GetRand(4) * 105 + 40);

	//�����ʒu�̐ݒ�
	location = Vector2D(random_x, -50.0f);

	//�����蔻��̐ݒ�
	box_size = Vector2D(31.0f, 60.0f);

	//�����̐ݒ�
	speed = 1.0f; //(float)(this->type * 2);
}

void Item2::Update(float speed)
{

	//�ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(0.0f, this->speed + speed);// + speed - 6);

}
void Item2::Draw() const
{

	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, type, TRUE);

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