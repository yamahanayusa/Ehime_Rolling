#include "stdafx.h"
#include "Chest.h"
#include "Chest.h"

Chest::Chest() 
{

}

Chest::~Chest()
{

}

bool Chest::Start() 
{
	//�`�F�X�g�̃��f����ǂݍ��ށB
	m_modelRender.Init("Assets/modelData/Chest.tkm");

	return true;
}

void Chest::Update() 
{
	//�ړ������B
	Move();

	//�G�`������̍X�V�����B
	m_modelRender.Update();

	//�v���C���[����R�C���Ɍ������x�N�g�����v�Z�B
	//Vector3 diff = m_player->m_position - m_position;
}

void Chest::Move()
{
	//�G�`������ɍ��W��������B
	m_modelRender.SetPosition(m_position);
}


void Chest::Render(RenderContext& rc)
{
	//coin��`�悷��B
	m_modelRender.Draw(rc);
}