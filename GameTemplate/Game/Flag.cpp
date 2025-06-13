#include "stdafx.h"
#include "Flag.h"
#include "Game.h"
#include "Score.h"
#include "Timer.h" 
#include "Player.h"
#include "GameClear.h"
#include "Stage01.h"
#include "Stage03.h"
#include "Stage04.h"
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
	m_stage01 = FindGO<Stage01>("stage01");
	m_stage03 = FindGO<Stage03>("stage03");
	m_stage04 = FindGO<Stage04>("stage04");
  
	switch (m_game->m_state)
	{
	case 1:
		m_transform->SetParent(m_stage01->m_transform);
		break;
	case 2:
		m_transform->SetParent(m_stage01->m_transform);
		break;
	case 3:
		m_transform->SetParent(m_stage03->m_transform);
		break;
	case 4:
		m_transform->SetParent(m_stage04->m_transform);
		break;
	case 5:
		break;
	}
	return true;
}

void Flag::Update()
{
	//更新処理。
	m_transform->UpdateTransform();

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
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Flag::Render(RenderContext& rc)
{
	//描画する。
	m_modelRender.Draw(rc);
}
