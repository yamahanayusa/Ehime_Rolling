#pragma once
class Score :public IGameObject
{
public:
	Score();
	~Score();

	void Update();
	void ResultScore();
	void Render(RenderContext& rc);

	FontRender m_resultRender;
	SpriteRender spriteRender;

	//Score
	FontRender m_ScoreFontRender;

	//メンバ変数
	int m_resultScore = 0;
};

