#pragma once

#include "../Utility/Vector2D.h"
#include "Barrier.h"

class Player
{
private:
	//�L����Ԃ��H
	bool is_active;
	//�摜�f�[�^
	int image;
	//�ʒu���W
	Vector2D location;
	//�����蔻��̑傫��
	Vector2D box_size;
	//���݂̃��[��
	int lane;
	//����
	float speed;
	//�̗�
	float hp;
	//�o���A�̖���
	int barrier_count;
	//�o���A
	Barrier* barrier;

public:
	Player();
	~Player();

	//����������
	void Initialize();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I��������
	void Finalize();

public:
	//�L���t���O�ݒ�
	void SetActive(bool flg);
	//�̗͌�������
	void DecreaseHp(float value);
	//�ʒu���W�擾
	Vector2D GetLocation()const;
	//�����蔻��̑傫���擾
	Vector2D GetBoxSize()const;
	////�����擾
	float GetSpeed()const;
	//�̗͎擾
	float GetHp()const;
	//�o���A�̖����擾
	int GetBarriarCount()const;
	//�o���A�L�����H���擾
	bool IsBarrier()const;
	//��������
	void Acceleration(float add);
	//���M���̌�������
	void YagiDecreHp(float value);

private:

	//�ړ�����
	void Movement();
	
};