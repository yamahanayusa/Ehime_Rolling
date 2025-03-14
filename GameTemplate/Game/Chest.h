#pragma once

class Player;
class Chest :public IGameObject
{
public:
	Chest();
	~Chest();
	bool Start();
	void Update();					//�X�V�����B
	void Render(RenderContext& rc);	//�`�揈���B
	void Move();					//�ړ������B

	ModelRender m_modelRender;		//���f�������_�\�B
	Vector3 m_position;				//���W�B
	Vector3 m_firstPosition;		//�ŏ��̍��W�B

	//Player* m_player;				//�v���C���[�B
};

