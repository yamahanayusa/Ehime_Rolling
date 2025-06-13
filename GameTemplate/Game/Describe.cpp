#include "stdafx.h"
#include "Describe.h"
#include "Game.h"
#include "StageSelect.h"
Describe::Describe()
{
	m_spriteRender.Init("Assets/sprite/describe3.dds", 1920.0f, 1080.0f);
}

Describe::~Describe()
{

}

bool Describe::Start()
{
	return true;
}

void Describe::Update()
{

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		m_stageSelect = NewGO<StageSelect>(0, "stageSelect");
		DeleteGO(this);
	}
}

void Describe::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}