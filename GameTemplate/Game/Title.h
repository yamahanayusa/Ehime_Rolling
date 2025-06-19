#pragma once

class Game;
class StageSelect;
class Describe;

class Title :public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	bool Start();
	void Render(RenderContext& rc);

private:
	SpriteRender m_spriteRender;
	Game*			m_game			= nullptr;
	StageSelect*	m_stageSelect	= nullptr;
	Describe*		m_describe		= nullptr;
};

