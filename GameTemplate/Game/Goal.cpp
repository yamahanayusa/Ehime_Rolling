#include "stdafx.h"
#include "Goal.h"
#include "Game.h"
#include "Player.h"
#include "Stage01.h"
#include "Stage02.h"
#include "Stage03.h"
#include "Stage04.h"
#include "Stage05.h"
#include "Transform.h"

Goal::Goal()
{
	m_transform = new Transform();			//Transformの生成。
}

Goal::~Goal()
{
	delete m_transform;						//Transformの削除
}

bool Goal::Start()
{
	//モデルの表示。	
	m_modelRender.Init("Assets/modelData/goal/goal.tkm");

	m_game	  = FindGO<Game>("game");
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

void Goal::Update()
{
	//更新処理。
	m_transform->UpdateTransform();

	//絵描きさんの更新処理。
	UpdateModelRenderer();
}

void Goal::UpdateModelRenderer()
{
	//絵描きさんに座標を教える。
	m_modelRender.SetPosition(m_transform->m_position);
	m_modelRender.SetRotation(m_transform->m_rotation);
	m_modelRender.SetScale(m_transform->m_scale);
	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Goal::Render(RenderContext& rc)
{
	//描画する。
	m_modelRender.Draw(rc);
}