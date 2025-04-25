#pragma once

class Game;
class Player : public IGameObject
{
public:

	Player();
	~Player();
	//繧ｹ繧ｿ繝ｼ繝・
	bool Start();
	//繧｢繝・・繝・・繝・
	void Update();
	//繝ｬ繝ｳ繝繝ｼ
	void Render(RenderContext& rc);

	Vector3                 m_position;//蠎ｧ讓吶・
	Vector3                 m_scale = Vector3::One;//繧ｹ繧ｱ繝ｼ繝ｫ
	
	Vector3                 m_moveSpeed;//遘ｻ蜍暮溷ｺｦ
	Vector3                 m_ballPosition;
	CharacterController     m_charaCon;//繧ｭ繝｣繝ｩ繧ｳ繝ｳ
	// 蜑帑ｽ薙・菴咲ｽｮ縺ｨ蝗櫁ｻ｢繧貞叙蠕励☆繧・
	Vector3 rbPos;
	Quaternion rbRot;
	Game* m_game;
	RigidBodyInitData rbInitData;
	RigidBody m_rigidBody;	// 蜑帑ｽ・
private:

	ModelRender m_ballRender;
	SphereCollider m_sphereCollider; // 繝懊・繝ｫ縺ｮ蠖｢迥ｶ

};