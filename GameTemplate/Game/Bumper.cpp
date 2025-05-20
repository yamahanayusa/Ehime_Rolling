#include "stdafx.h"
#include "Bumper.h"
#include "Game.h"
#include "Player.h"

Bumper::Bumper()
{

}

Bumper::~Bumper()
{

}

bool Bumper::Start()
{
	m_game = FindGO<Game>("game");
	//m_player = FindGO<Player>("player");
	m_modelRender.Init("Assets/modelData/bumper/bumper.tkm");
	m_Object.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetWorldMatrix(0));
	m_modelRender.SetScale(1.0f, 1.0f, 1.0f);
	return true;
}

void Bumper::Update()
{
	Move();

	Rotation();
}

void Bumper::Move()
{
	//ŠG•`‚«‚³‚ñ‚ÉÀ•W‚ğ‹³‚¦‚éB
	m_modelRender.SetPosition(m_position);
	//ŠG•`‚«‚³‚ñ‚ÌXVˆ—B
	m_modelRender.Update();
}

void Bumper::Rotation()
{

}

void Bumper::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}
