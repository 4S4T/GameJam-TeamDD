#pragma once

#include"../Utility/Vector2D.h"
#include"Item_Base.h"

class Enemy3 :public Item_Base
{
public:
	Enemy3(int type); //int handle);
	~Enemy3();

	//����������
	void Initialize(int set_lane) override;
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

