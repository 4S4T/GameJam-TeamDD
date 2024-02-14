#pragma once

#include"../Utility/Vector2D.h"

class Enemy3
{

private:
	//�^�C�v
	int type;
	//�摜
	int image;
	//����
	float speed;
	//�ʒu���
	Vector2D location;
	//�����蔻��̑傫��
	Vector2D box_size;

public:
	Enemy3(int type); //int handle);
	~Enemy3();

	//����������
	void Initialize();
	//�X�V����
	void Update(float speed);
	//�`�揈��
	void Draw() const;
	//�I��������
	void Finalize();

	//�^�C�v�擾
	int GetType() const;
	//�ʒu���̎擾
	Vector2D GetLocation() const;
	//�����蔻��̑傫�����擾
	Vector2D GetBoxSize() const;
};

