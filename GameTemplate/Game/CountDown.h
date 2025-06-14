#pragma once
class CountDown:public IGameObject
{
public:
	CountDown();
	~CountDown();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	//GO!が出ているかの判定。
	bool GetShowGO()const {
		return m_showGO;
	}

private:
	FontRender m_fontRender;

	Vector3     m_position;					//表示位置。
	int			m_currentCount	= 3;		//今表示している数字。
	bool		m_showGO		= true;		//表示するかどうかのフラグ。
	float		m_goTimer		= 0.0f;		//GO!が表示されてからの経過時間。
	float		m_goDuration	= 1.5f;		//GO!を表示する時間（秒）。
	float		m_timer			= 0.0f;		//経過時間を記録。
	float		m_fadeTimer		= 0.0f;     //フェード用タイマー。
	float		m_fadeDuration	= 0.5f;		//フェードイン時間（秒）。
	const float m_interval		= 1.3f;		//1.3秒ごとにカウントダウン。
};

