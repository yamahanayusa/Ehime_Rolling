#pragma once
class Timer;
class Score :public IGameObject
{
public:
	Score();
	~Score();
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	int GetTortalScore()
	{
		return m_tortalScore;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="addScore"></param>
	void AddItemGetScore(int addScore)
	{
		m_itemGetScore += addScore * m_buffMultipier;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="multipier"></param>
	/// <param name="buffSecond"></param>
	void SetBuffMultipier(float multipier,float buffSecond)
	{
		m_buffMultipier = multipier;
		m_buffSecond = buffSecond;
	}
private:	
	/// <summary>
	/// アイテム取得時のスコアの計算。
	/// </summary>
	void ResultScoreCalc();

	/// <summary>
	/// 残り時間によるスコアの計算。
	/// </summary>
	void TimeScoreCalc();
	
	/// <summary>
	/// リザルトスコアの表示。
	/// </summary>
	void ResultScoreDisp();
private:
	FontRender m_scoreFontRender;

	Timer* m_timer;
	
	int	m_itemGetScore = 0;		//アイテム取得時のスコア。
	int	m_timeScore = 0;		//残り時間から計算されたスコア。
	int	m_tortalScore = 0;		//アイテム取得時のスコアと残り時間から計算されたスコアの合計。

	float m_buffMultipier = 1.0f;	//バフの倍率。初期値は1。
	float m_buffSecond = 0;
};

