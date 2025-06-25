#pragma once

class Game;
class Score;
class Timer;
class Flag;

//ゲームクリア
class GameClear :public IGameObject
{
public:
	GameClear();
	~GameClear();

	bool Start()override;
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);
	//
	void TortalScore();

private:
	SpriteRender	m_spriteRender;
	FontRender		m_fontRender;

	Game*		m_game		= nullptr;
	Score*		m_score		= nullptr;
	Timer*		m_timer		= nullptr;
	Flag*		m_chest		= nullptr;
	SoundSource* m_soundSource = nullptr;
};

