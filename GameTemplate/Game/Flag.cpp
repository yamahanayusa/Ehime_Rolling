#include "stdafx.h"
#include "Flag.h"
#include "Game.h"
#include "Score.h"
#include "Timer.h" 
#include "Player.h"
#include "GameClear.h"
#include "Stage.h"
#include "Transform.h"

Flag::Flag()
{
	m_transform = new Transform();
}

Flag::~Flag()
{
	delete m_transform;
}

bool Flag::Start()
{
	//モデルの表示。
	m_modelRender.Init("Assets/modelData/flag.tkm");

	m_game = FindGO<Game>("game");
	m_score = FindGO<Score>("score");
	m_timer = FindGO<Timer>("timer");
	m_player = FindGO<Player>("player");
	m_stage = FindGO<Stage>("stage");
  
	m_transform->SetParent(m_stage->m_transform);
	return true;
}

void Flag::Update()
{
	//更新処理。
	m_transform->Update();

	//絵描きさんの更新処理。
	UpdateModelRenderer();

	//プレイヤーからチェストに向かうベクトルを計算。
	Vector3	diff = m_player->rbPos - m_transform->m_position;

	//ベクトルの長さが120.0fより小さかったら。
	if (diff.Length() <= 120.0f)
	{
		m_clearFlag = true;
		if (m_clearFlag == true)
		{
			const int m_resultTime  = m_timer->GetTime();
			m_score->GetTortalScore();
		}
		DeleteGO(this);
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(m_game);
	}
}

void Flag::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->GetPosition());
	m_modelRender.SetRotation(m_transform->GetRotation());
	m_modelRender.SetScale(m_transform->GetScale());
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Flag::Render(RenderContext& rc)
{
	//描画する。
	m_modelRender.Draw(rc);
}
