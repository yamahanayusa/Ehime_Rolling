#pragma once
class Game;
class Score;
class Chest;
class Timer;
class Mikan;
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

	void SetResultTime(float resulttime) {
		m_resultTime = resulttime;
	}
private:
	int							m_tortalScore = 0;
	bool						m_clearFlag = false;

	int m_resultScore = 0;
	//メンバ変数
	SpriteRender m_spriteRender; //スプライトレンダー
	FontRender m_fontRender; //
	Game* m_game;
	Score* m_score;
	Chest* m_chest;
	Timer* m_timer;
	Mikan* m_mikan;

	float m_resultTime = 0;
};

