#include "stdafx.h"
#include "Item.h"
#include "Game.h"
#include "Score.h"
#include "Timer.h" 
#include "Player.h"
#include "Stage.h"
#include "Transform.h"


namespace ItemStetus {
	const float FLY_UP_VELOCITY = 800.0f;	//上方向に飛ばす時の初速
	const float FLY_UP_TIME = 0.5f;			//上昇する時間
}

Itembase::Itembase()
{
	m_transform = new Transform;
}

Itembase::~Itembase()
{
	delete m_transform;
}

bool Itembase::Start()
{
	m_score = FindGO<Score>("score");
	m_player = FindGO<Player>("player");
	m_stage = FindGO<Stage>("stage");
	// ステージのTransformを親に設定
	if (m_stage && m_stage->GetTransform()) {
		m_transform->SetParent(m_stage->GetTransform());
	}
	AddStart();
	// ItemFly(); ← ここを削除
	return true;
}

void Itembase:: Update()
{
	ItemDistance();
	//更新処理。
	m_transform->Update();
	//ItemFly();
		//絵描きさんの更新処理。
	m_modelRender.Update();

	Move();

	ItemFly();
}

void Itembase::ItemDistance()
{
	//プレイヤーがみかんに向かうベクトルを計算。
	Vector3 diff = m_player->rbPos - m_transform->m_position;

	//ベクトルの長さが120.0fより小さかったら、かつ未取得なら
	if (diff.Length() <= 120.0f && !m_isCollected) {
		m_isCollected = true; // 取得済みフラグを立てる

		if (!m_isSE) {
			PlaySE();
			m_isSE = true;
		}

		m_isFlying = true; // 取得時のみフラグを立てる
		m_velocity.y = ItemStetus::FLY_UP_VELOCITY; // 上方向速度をセット
		m_flyUpTimer = 0.0f; // タイマー初期化
		// --- ここまで修正 ---
		ItemFly();

		switch (m_itemKind)
		{
		case Kind::SCORE:
			m_score->AddScore(m_itemScore); // スコア加算は一度だけ
			break;
		case Kind::BUFF:
			m_buffTimer -= g_gameTime->GetFrameDeltaTime();
			m_score->SetBuffMultipier(JakotenStetus::BUFF_MULTIPIER, JakotenStetus::BUFF_TIME);
			break;
		default:
			break;
		}
	}

	if (!m_isCollected)
	{
		return;
	}
}

void Itembase::PlaySE()
{
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(5);
	se->Play(false);
}

void Itembase::ItemFly()
{
	if (m_isFlying) {
		m_flyUpTimer += g_gameTime->GetFrameDeltaTime();
		m_transform->m_localPosition.y += m_velocity.y * g_gameTime->GetFrameDeltaTime();
			m_velocity.y -= 2000.0f * g_gameTime->GetFrameDeltaTime();	// 重力
			//上昇時間がFLY_UP_TIMEを超えたら削除。
			if (m_flyUpTimer >= ItemStetus::FLY_UP_TIME) {
				DeleteGO(this);
				m_isFlying = false;
			}
	}
}

void Itembase::Move()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
}

void Itembase::Render(RenderContext& rc)
{
	//描画する。
	m_modelRender.Draw(rc);
}


