#include "stdafx.h"
#include "Kiwi.h"
#include "Game.h"
#include "Score.h"
#include "Timer.h" 
#include "Player.h"
#include "Stage04.h"
#include "Stage05.h"
#include "Transform.h"

namespace {
	const int SCORE = 200;					//キウイのスコア
	const float FLY_UP_VELOCITY = 800.0f;	//上方向に飛ばす時の初速
	const float FLY_UP_TIME = 0.5f;			//上昇する時間
}

Kiwi::Kiwi()
{
	m_transform = new Transform();			//Transformの生成。
}

Kiwi::~Kiwi()
{
	delete m_transform;						//Transformの削除。
}

bool Kiwi::Start()
{
	//モデルの表示。
	m_modelRender.Init("Assets/modelData/Kiwi/Kiwi.tkm");
	
	m_game = FindGO<Game>("game");
	m_score = FindGO<Score>("score");
	m_stage04 = FindGO<Stage04>("stage04");
	m_stage05 = FindGO<Stage05>("stage05");
	switch (m_game->m_state)
	{
	case 4:
		m_transform->SetParent(m_stage04->m_transform);
		break;
	case 5:
		m_transform->SetParent(m_stage05->m_transform);
		break;
	}

	return true;
}

void Kiwi::Update()
{
	m_player = FindGO<Player>("player");

	//更新処理。
	m_transform->UpdateTransform();

	//絵描きさんの更新処理。
	UpdateModelRenderer();

	if (m_isCollected) {
		m_flyUpTimer += g_gameTime->GetFrameDeltaTime();
		m_transform->m_localPosition.y += m_velocity.y * g_gameTime->GetFrameDeltaTime();
		m_velocity.y -= 2000.0f * g_gameTime->GetFrameDeltaTime(); // 重力

		if (m_flyUpTimer >= FLY_UP_TIME) {
			DeleteGO(this);
		}
		m_modelRender.SetPosition(m_transform->m_position);
		m_modelRender.Update();
		return;
	}

	//プレイヤーがキウイに向かうベクトルを計算。
	Vector3 diff = m_player->rbPos - m_transform->m_position;
	//ベクトルの長さが120.0fより小さかったら。
	if (diff.Length() <= 60.0f)
	{
		m_isCollected = true;
		m_transform->m_position = m_transform->m_position;
		m_velocity = Vector3(0, FLY_UP_VELOCITY, 0); // 上方向にぶっ飛ばす
		m_flyUpTimer = 0.0f;
		//スコアの加算。
		m_score->AddItemGetScore(SCORE);
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(5);
		se->Play(false);

		m_score->SdRender(SCORE);

		//DeleteGO(this);

		return;
	}
	return;
}

void Kiwi::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Kiwi::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
