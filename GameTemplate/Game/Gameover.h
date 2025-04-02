#pragma once
class Game;
class GameOver :public IGameObject
{
public:
	GameOver();
	~GameOver();
	bool Start() override;
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	//メンバ変数
	SpriteRender spriteRender; //スプライトレンダー
	Game* m_game;
};

