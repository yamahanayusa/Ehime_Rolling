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
	/// ƒAƒCƒeƒ€Žæ“¾Žž‚ÌƒXƒRƒA‚ÌŒvŽZB
	/// </summary>
	void ResultScoreCalc();

	/// <summary>
	/// Žc‚èŽžŠÔ‚É‚æ‚éƒXƒRƒA‚ÌŒvŽZB
	/// </summary>
	void TimeScoreCalc();
	
	/// <summary>
	/// ƒŠƒUƒ‹ƒgƒXƒRƒA‚Ì•\Ž¦B
	/// </summary>
	void ResultScoreDisp();
private:
	FontRender m_scoreFontRender;

	Timer* m_timer;
	
	int	m_itemGetScore = 0;		//ƒAƒCƒeƒ€Žæ“¾Žž‚ÌƒXƒRƒAB
	int	m_timeScore = 0;		//Žc‚èŽžŠÔ‚©‚çŒvŽZ‚³‚ê‚½ƒXƒRƒAB
	int	m_tortalScore = 0;		//ƒAƒCƒeƒ€Žæ“¾Žž‚ÌƒXƒRƒA‚ÆŽc‚èŽžŠÔ‚©‚çŒvŽZ‚³‚ê‚½ƒXƒRƒA‚Ì‡ŒvB

	float m_buffMultipier = 1.0f;	//ƒoƒt‚Ì”{—¦B‰Šú’l‚Í1B
	float m_buffSecond = 0;
};

