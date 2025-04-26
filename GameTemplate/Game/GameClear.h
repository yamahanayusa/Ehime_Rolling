#pragma once
class Game;
class Score;
class Chest;
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
	//void TortalScore();

	//メンバ変数
	SpriteRender m_spriteRender; //スプライトレンダー
	FontRender m_fontRender; //
	Game* m_game;
	Score* m_score;
	Chest* m_chest;
};

