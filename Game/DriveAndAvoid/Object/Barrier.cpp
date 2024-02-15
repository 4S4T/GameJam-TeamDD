#include "Barrier.h"
#include "DxLib.h"

Barrier::Barrier() : life_span(1000)
{
	//�摜�ǂݍ���
	LoadDivGraph("Resource/images/pakupakuneko.png", 6, 6, 1, 70, 88, image);

	//�G���[�`�F�b�N
	//if (image == -1)
	//{
	//	throw ("Resource/images/barrier.png������܂���/n");
	//}
}

Barrier::~Barrier()
{
	//�]�����񂾉摜���폜
	DeleteGraph(image[6]);
}

//�`�揈��
void Barrier::Draw(const Vector2D& location)
{

	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image[0], TRUE);
}

//�������s�������H
bool Barrier::IsFinished(float speed)
{
	life_span -= speed;
	return (life_span <= 0);
}