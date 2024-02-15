#pragma once

#include"../Utility/Vector2D.h"

class Item_Base
{
protected:
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
	Item_Base(int type);
	~Item_Base();

	//����������
	virtual void Initialize();
	//�X�V����
	void Update(float speed);
	//�`�揈��
	virtual void Draw() const;
	//�I��������
	void Finalize();

	//�^�C�v�擾
	int GetType() const;
	//�ʒu���̎擾
	virtual Vector2D GetLocation() const;
	//�����蔻��̑傫�����擾
	virtual Vector2D GetBoxSize() const;
};

