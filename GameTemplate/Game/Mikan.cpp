#include "stdafx.h"
#include "Mikan.h"
#include "Game.h"
#include "Score.h"
#include "Timer.h" 
#include "Player.h"
#include "Stage.h"
#include "Transform.h"

namespace {
	const int SCORE = 100;
}

Mikan::Mikan()
{
	m_transform = new Transform();
}

Mikan::~Mikan()
{
	delete m_transform;
}

bool Mikan::Start()
{
	//モデルの表示。	
	m_modelRender.Init("Assets/modelData/mikan.tkm");

	m_game = FindGO<Game>("game");
	m_score = FindGO<Score>("score");
	m_stage = FindGO<Stage>("stage");

	m_transform->SetParent(m_stage->m_transform);
	return true;
}

void Mikan::Update()
{
	m_player = FindGO<Player>("player");

		m_modelRender.SetPosition(m_transform->m_position);
		m_modelRender.SetRotation(m_transform->m_rotation);
		m_modelRender.SetScale(m_transform->m_scale);
		m_transform->Update();
		m_modelRender.Update();

	//移動処理。
	Move();

	//更新処理。
	m_transform->Update();

	//絵描きさんの更新処理。
	m_modelRender.Update();

	//プレイヤーがみかんに向かうベクトルを計算。
	Vector3 diff = m_player->rbPos - m_transform->m_position;
	//ベクトルの長さが120.0fより小さかったら。

	if (diff.Length() <= 120.0f&&!m_isCollected)
	{

		DeleteGO(this);
		//スコアの加算。
		m_score->AddItemGetScore(SCORE);
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(5);
		se->Play(false);

		m_score->SdRender(SCORE);
	}
	return;
}

void Mikan::Move()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
}

void Mikan::Render(RenderContext& rc)
{
	//描画する。
	m_modelRender.Draw(rc);
}
