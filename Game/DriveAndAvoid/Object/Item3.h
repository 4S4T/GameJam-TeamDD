#pragma once
#pragma once

#include"../Utility/Vector2D.h"
#include"Item_Base.h"

class Item3 : public Item_Base
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
	Item3(int type); //int handle);
	~Item3();

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

