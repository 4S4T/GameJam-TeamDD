#include "Enemy1.h"
#include "DxLib.h"

Enemy1::Enemy1(int type) : type(type), image(), speed(0.0f), location(0.0f), box_size(0.0f)
{

}

Enemy1::~Enemy1()
{

}

//����������
void Enemy1::Initialize()
{

	image = LoadGraph("Resource/images/gomi_namagomi.png", image);

	//�o��������X���W�p�^�[���擾
	float random_x = (float)(GetRand(4) * 105 + 40);

	//�����ʒu�̐ݒ�
	location = Vector2D(random_x, -50.0f);

	//�����蔻��̐ݒ�
	box_size = Vector2D(31.0f, 60.0f);

	//�����̐ݒ�
	speed = 1.0f; //(float)(this->type * 2);
}

void Enemy1::Update(float speed)
{

	//�ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(0.0f, this->speed + speed);// + speed - 6);

}
void Enemy1::Draw() const
{

	//�G�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Enemy1::Finalize()
{

}

//�G�̃^�C�v���擾
int Enemy1::GetType() const
{

	return type;

}

//�ʒu�����擾
Vector2D Enemy1::GetLocation()const
{

	return location;

}

//�����蔻��̑傫���擾
Vector2D Enemy1::GetBoxSize() const
{
	return box_size;
}