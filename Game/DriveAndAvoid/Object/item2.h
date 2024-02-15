#pragma once

#include"../Utility/Vector2D.h"
#include"Item_Base.h"

class Item2 :public Item_Base
{
public:
	Item2(int type); //int handle);
	~Item2();

	//����������
	void Initialize();
	//�`�揈��
	void Draw() const override;
	//�I��������
	void Finalize();

	//�^�C�v�擾
	int GetType() const;
	//�ʒu���̎擾
	Vector2D GetLocation() const override;
	//�����蔻��̑傫�����擾
	Vector2D GetBoxSize() const override;
};

