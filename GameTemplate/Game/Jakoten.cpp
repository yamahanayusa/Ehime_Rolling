#include "stdafx.h"
#include "Jakoten.h"
#include "Game.h"
#include "Player.h"
#include "Score.h"
#include "Mikan.h"
#include "Timer.h"
//#include "Stage03.h"
#include "Stage05.h"
#include "Transform.h"

//定数。
namespace {
	const float BUFF_MULTIPIER = 2.0f;		//バフの倍率。
	const float BUFF_TIME = 10.0f;			//バフの継続時間。
	const float FLY_UP_VELOCITY = 800.0f;	//上方向に飛ばす時の初速
	const float FLY_UP_TIME = 0.5f;			//上昇する時間
}

Jakoten::Jakoten()
{
	m_transform = new Transform;			//Transformの生成。
}

Jakoten::~Jakoten()
{
	delete m_transform;						//Transformの削除。
}

bool Jakoten::Start()
{
	//モデルの初期化。
	m_modelRender.Init("Assets/modelData/Jakoten.tkm");
	m_modelRender.SetScale(1.0f, 1.0f, 1.0f);
	m_game = FindGO<Game>("game");
	m_player = FindGO<Player>("player");
	m_score = FindGO<Score>("score");
	m_timer = FindGO<Timer>("timer");
	//m_stage03 = FindGO<Stage03>("stage03");
	m_stage05 = FindGO<Stage05>("stage05");

	switch (m_game->m_state)
	{
	case 5:
		m_transform->SetParent(m_stage05->m_transform);
	}
	m_buffTimer = BUFF_TIME;
	return true;
}

void Jakoten::Update()
{
	m_player = FindGO<Player>("player");

	if (m_isCollected) {
		m_flyUpTimer += g_gameTime->GetFrameDeltaTime();								//上昇時間
		m_transform->m_localPosition.y += m_velocity.y * g_gameTime->GetFrameDeltaTime();
		m_velocity.y -= 2000.0f * g_gameTime->GetFrameDeltaTime();						// 重力

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

	//アイテムの獲得。
	if (diff.Length() <= 60.0f)
	{
		m_isCollected = true;									//取得済みフラグを立てる。
		m_transform->m_position = m_position;					//初期位置に戻さずにその場て飛ばす
		m_velocity = Vector3(0, FLY_UP_VELOCITY, 0);			// 上方向に飛ばす
		m_flyUpTimer = 0.0f;									//上昇時間のリセット
		m_buffTimer -= g_gameTime->GetFrameDeltaTime();			//バフタイマーを減らす
		m_score->SetBuffMultipier(BUFF_MULTIPIER, BUFF_TIME);	//バフ倍率と継続時間
		//DeleteGO(this);
		return;
	}		
	return;
}

void Jakoten::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Jakoten::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}




