#pragma once

class RankingData
{
private:

	//スコアデータ
	int score[6];
	//ランクデータ
	int rank[6];
	//名前データ
	char name[6][15];

public:
	RankingData();
	~RankingData();

	//初期処理
	void Initialize();
	//終了処理
	void Finlize();

public:

	//ランキングデータの設定
	void SetRankingData(int score, const char* name);
	//スコア取得処理
	int GetScore(int value)const;
	//ランク取得処理
	int GetRank(int value)const;
	//名前取得処理
	const char* GetName(int value) const;

private:
	//データ入れ替え処理
	void SortData();
};