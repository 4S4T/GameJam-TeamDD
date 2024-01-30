#pragma once

class RankingData
{
private:

	//�X�R�A�f�[�^
	int score[6];
	//�����N�f�[�^
	int rank[6];
	//���O�f�[�^
	char name[6][15];

public:
	RankingData();
	~RankingData();

	//��������
	void Initialize();
	//�I������
	void Finlize();

public:

	//�����L���O�f�[�^�̐ݒ�
	void SetRankingData(int score, const char* name);
	//�X�R�A�擾����
	int GetScore(int value)const;
	//�����N�擾����
	int GetRank(int value)const;
	//���O�擾����
	const char* GetName(int value) const;

private:
	//�f�[�^����ւ�����
	void SortData();
};