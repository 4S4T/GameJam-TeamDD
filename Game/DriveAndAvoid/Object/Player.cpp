#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

Player::Player() : is_active(false), image(NULL), location(0.0f), box_size(0.0f), lane(0), speed(0.0f), hp(0.0f), barrier_count(0),

barrier(nullptr)
{

}

Player::~Player()
{

}

//����������
void Player::Initialize()
{

	is_active = true;

	location = Vector2D(60.0f, 300.0f);
	box_size = Vector2D(box_x, box_y);
	lane = 3;
	speed = 1.0f;
	hp = 1000;
	barrier_count = 3;

	//�摜�̓ǂݍ���
	image = LoadGraph("Resource/images/car1pol.bmp");

	//�G���[�`�F�b�N
	if (image == -1)
	{
		throw ("Resource/images/car1pol.bmp������܂���/n");
	}
}

//�X�V����
void Player::Update()
{

	//����s�\��Ԃł���΁A���M����]������
	if (!is_active)
	{
		
		speed = 1.0f;

		return;
	}

	//�H���Q�[�W�̌���
	hp--;

	//�ړ�����
	Movement();


	if (InputControl::GetButtonDown(XINPUT_BUTTON_START))
	{
		//is_active = false;
	}

	//�o���A����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B) && barrier_count > 0)
	{
		if (barrier == nullptr)
		{
			barrier_count--;
			barrier = new Barrier;
		}
	}

	//�o���A����������Ă�����A�X�V���s��
	if (barrier != nullptr)
	{
		//�o���A���o�߂������H���Ă�����A�폜����
		if (barrier->IsFinished(this->speed))
		{
			delete barrier;
			barrier = nullptr;
		}
	}
}

//�`�揈��
void Player::Draw()
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1, 0, image, TRUE);

	//�o���A����������Ă�����A�`����s��
	if (barrier != nullptr)
	{
		barrier->Draw(this->location);
	}
}

//�I��������
void Player::Finalize()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(image);

	//�o���A����������Ă�����A�폜����
	if (barrier != nullptr)
	{
		delete barrier;
	}
}

//��Ԑݒ菈��
void Player::SetActive(bool flg)
{
	this->is_active = flg;
}

//�̗͌�������
void Player::DecreaseHp(float value)
{
	this->hp += value;
}

//�ʒu���擾����
Vector2D Player::GetLocation()const
{
	return this ->location;
}

//�����蔻��̑傫���擾����
Vector2D Player::GetBoxSize()const
{
	return this->box_size;
}

//�����擾����
float Player::GetSpeed()const
{
	return this->speed;
}

//�̗͎擾����
float Player::GetHp() const
{
	return this->hp;
}

//�o���A�����擾����
int Player::GetBarriarCount()const
{
	return this->barrier_count;
}

//�o���A�L�����H���擾
bool Player::IsBarrier() const
{
	return (barrier != nullptr);
}

//�ړ�����
void Player::Movement() 
{

	Vector2D move = Vector2D(0.0f);

	//�\���ړ�����
	//if (InputControl::GetButton(XINPUT_BUTTON_DPAD_LEFT))
	//{
	//	move += Vector2D(-1.0f, 0.0f);
	//	angle = -DX_PI_F / 18;
	//}
	//if (InputControl::GetButton(XINPUT_BUTTON_DPAD_RIGHT))
	//{
	//	move += Vector2D(1.0f, 0.0f);
	//		angle = DX_PI_F / 18;
	//}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		if (lane > 0)
		{
			lane--;
			location = Vector2D(60.0f, (50.0f * lane) + 150.0f);
		}
	}
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{

		if (lane < 5)
		{
			lane++;
			location = Vector2D(60.0f, (50.0f * lane) + 150.0f);
		}
	}

	//��ʊO�ɂ����Ȃ��悤�ɐ�������
	if ((location.x < box_size.x) || (location.x >= 640.0f - 180.0f) || (location.y < box_size.y) || (location.y >= 510.0f - box_size.y))
	{
		location -= move;
	}
}

//����������
void Player::Acceleration()
{
	speed++;
}