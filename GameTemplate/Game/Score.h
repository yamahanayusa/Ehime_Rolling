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
		m_tortalScore = m_itemGetScore + m_timeScore;
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

	/// <summary>
	/// sdScore の値に基づいて SD をレンダリングします。
	/// </summary>
	/// <param name="sdScore">レンダリングに使用する SD のスコア。</param>
	void SdRender(int sdScore);
	/// <summary>
	/// SDレンダラーの状態をクリアします。
	/// </summary>
	void ClearSdRender();
	/// <summary>
	/// SDレンダリングを更新します。
	/// </summary>
	/// <param name="deltaTime">前回の更新からの経過時間（秒単位）。</param>
	void UpdateSdRender(float deltaTime);

private:	
	/// <summary>
	/// 
	/// </summary>
	void ResultScoreCalc();

	/// <summary>
	/// 
	/// </summary>
	void TimeScoreCalc();
	
	/// <summary>
	///
	/// </summary>
	void ResultScoreDisp();

private:
	FontRender m_scoreFontRender;
	SpriteRender m_spriteRender;
	FontRender m_sdRender;			//スコア表示

	Timer* m_timer;
	
	int	m_itemGetScore = 0;		//アイテムを取ったときのスコア
	int	m_timeScore = 0;		//残り時間のスコア
	int	m_tortalScore = 0;		//トータルスコア
	int m_itemPoint = 0;
	int m_sdRenderScore = 0;	//取った時だけ表示されるスコア

	float m_buffMultipier = 1.0f;	//バフの倍率
	float m_buffSecond = 0;			//バフの時間
	float m_sdRenderTimer = 0.0f;

	bool m_isSdRenderActive = false;
	bool m_isJakotenBuff = false;
};

