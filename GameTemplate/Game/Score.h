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

	//ƒƒ“ƒo•Ï”
	int m_resultScore = 0;
};

