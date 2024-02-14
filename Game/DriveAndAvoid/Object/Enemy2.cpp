#include "Enemy2.h"
#include "DxLib.h"

Enemy2::Enemy2(int type) : type(type), image(), speed(0.0f), location(0.0f), box_size(0.0f)
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
	float random_y = (float)(GetRand(4) * 50 + 150);

	//�����ʒu�̐ݒ�
	location = Vector2D(550.0f,random_y);

	//�����蔻��̐ݒ�
	box_size = Vector2D(25.0f, 25.0f);

	//�����̐ݒ�
	speed = 1.0f; //(float)(this->type * 2);
}

void Enemy2::Update(float speed)
{

	//�ʒu���Ɉړ��ʂ����Z����
	location -= Vector2D(this->speed+speed,0.0f);// + speed - 6);

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