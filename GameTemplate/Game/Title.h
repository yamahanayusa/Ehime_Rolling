#pragma once
class Game;
//class Score;
class Title :public IGameObject
{
public:
	Title();
	~Title();
	void Update();
	bool Start();
	//描画関数。
	void Render(RenderContext& rc);
	//スプライトレンダ―。
	SpriteRender m_spriteRender;
	Game* m_game;
};

