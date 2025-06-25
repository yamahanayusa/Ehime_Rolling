#pragma once

class Game;

class TimeOver :public IGameObject
{
public:
	TimeOver();
	~TimeOver();
	bool Start() override;
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

private:
	SpriteRender	spriteRender;
	Game*	m_game	= nullptr;
	SoundSource* m_soundSource = nullptr;
};

