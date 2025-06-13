#include "stdafx.h"
#include "Mikan.h"
#include "Game.h"
#include "Score.h"
#include "Timer.h" 
#include "Player.h"
#include "Stage01.h"
#include "Stage02.h"
#include "Stage03.h"
#include "Stage04.h"
#include "Stage05.h"
#include "Transform.h"

namespace {
	const int SCORE = 100;					//みかんのスコア
	const float FLY_UP_VELOCITY = 800.0f;	//上方向に飛ばす時の初速
	const float FLY_UP_TIME = 0.5f;			//上昇する時間
}

Mikan::Mikan()
{
	m_transform = new Transform();			//Transformの生成。
}

Mikan::~Mikan()
{
	delete m_transform;						//Transformの削除
}

bool Mikan::Start()
{
	//モデルの表示。	
	m_modelRender.Init("Assets/modelData/mikan.tkm");

	m_game = FindGO<Game>("game");
	m_score = FindGO<Score>("score");
	m_stage01 = FindGO<Stage01>("stage01");
	m_stage02 = FindGO<Stage02>("stage02");
	m_stage03 = FindGO<Stage03>("stage03");
	m_stage04 = FindGO<Stage04>("stage04");
	m_stage05 = FindGO<Stage05>("stage05");

	switch (m_game->m_state)
	{
	case 1:
		m_transform->SetParent(m_stage01->m_transform);
		break;
	case 2:
		m_transform->SetParent(m_stage02->m_transform);
		break;
	case 3:
		m_transform->SetParent(m_stage03->m_transform);
		break;
	case 4:
		m_transform->SetParent(m_stage04->m_transform);
		break;
	case 5:
		m_transform->SetParent(m_stage05->m_transform);
		break;
	}
	return true;
}

void Mikan::Update()
{
	m_player = FindGO<Player>("player");

	// 取得後のぶっ飛ばし処理
	if (m_isCollected) {
		m_flyUpTimer += g_gameTime->GetFrameDeltaTime();
		m_transform->m_localPosition.y += m_velocity.y * g_gameTime->GetFrameDeltaTime();
		m_velocity.y -= 2000.0f * g_gameTime->GetFrameDeltaTime();	// 重力

		//上昇時間がFLY_UP_TIMEを超えたら削除。
		if (m_flyUpTimer >= FLY_UP_TIME) {
			DeleteGO(this);
		}

		m_modelRender.SetPosition(m_transform->m_position);
		m_modelRender.Update();
		return;
	}

	//更新処理。
	m_transform->UpdateTransform();

	//絵描きさんの更新処理。
	UpdateModelRenderer();

	//プレイヤーがみかんに向かうベクトルを計算。
	Vector3 diff = m_player->rbPos - m_transform->m_position;
	//ベクトルの長さが120.0fより小さかったら。

	if (diff.Length() <= 120.0f&&!m_isCollected)
	{
		m_isCollected = true;							//取得済みフラグを立てる。
		m_velocity = Vector3(0, FLY_UP_VELOCITY, 0);	// 上方向にぶっ飛ばす
		m_flyUpTimer = 0.0f;							// 上昇時間をリセット
		//DeleteGO(this);
		//スコアの加算。
		m_score->AddItemGetScore(SCORE);
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(5);
		se->Play(false);

		m_score->SdRender(SCORE);
		return;
	}
	return;
}

void Mikan::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Mikan::Render(RenderContext& rc)
{
	//描画する。
	m_modelRender.Draw(rc);
}
