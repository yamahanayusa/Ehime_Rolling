#pragma once

class Game;
class StageSelect;

class Describe :public IGameObject
{
public:
	Describe();
	~Describe();

	void Update();
	bool Start();

	void Render(RenderContext& rc);

	SpriteRender	m_spriteRender;

	Game*			m_game			 = nullptr;
	StageSelect*	m_stageSelect	 = nullptr;
};

