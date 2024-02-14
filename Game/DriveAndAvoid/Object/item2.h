#pragma once

#include"../Utility/Vector2D.h"

class Item2
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
	Item2(int type); //int handle);
	~Item2();

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

