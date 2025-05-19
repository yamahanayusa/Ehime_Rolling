#include "stdafx.h"
#include "Jakoten.h"
#include "Game.h"
#include "Player.h"
#include "Score.h"
#include "Mikan.h"
#include "Timer.h"

//定数。
namespace {
	const float BUFF_MULTIPIER = 2.0f;	//バフの倍率。
	const float BUFF_TIME = 10.0f;     //バフの継続時間。
}

Jakoten::Jakoten()
{

}

Jakoten::~Jakoten()
{

}

bool Jakoten::Start()
{
	//モデルの初期化。
	m_modelRender.Init("Assets/modelData/Jakoten.tkm");
	m_modelRender.SetScale(1.0f, 1.0f, 1.0f);

	m_player = FindGO<Player>("player");
	m_score = FindGO<Score>("score");
	m_timer = FindGO<Timer>("timer");

	m_buffTimer = BUFF_TIME;
	return true;
}

void Jakoten::Update()
{
	Move();

	Rotation();

	//プレイヤーがみかんに向かうベクトルを計算。
	Vector3 diff = m_player->rbPos - m_position;
	//アイテムの獲得。
	if (diff.Length() <= 120.0f)
	{
		m_buffTimer -= g_gameTime->GetFrameDeltaTime();
		m_score->SetBuffMultipier(BUFF_MULTIPIER, BUFF_TIME);
		DeleteGO(this);
	}		
}

void Jakoten::Move()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_position);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}
void Jakoten::Rotation()
{

}
void Jakoten::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}




