#pragma once

class Player;
class Transform;

//追加

class Stage01 :public IGameObject
{
public:
	Stage01();
	~Stage01();
	//スタート
	bool Start();
	//アップデート
	void  Update();
	//回転処理
	void Rotation();
	//レンダー
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

	Matrix GetWorldMatrix() const
	{
		return m_modelRender.GetWorldMatrix(0);
	}

	Vector3 m_scale = Vector3::One;//大きさ
	//回転を設定する
	Quaternion addRot;
	Quaternion addLot;
	Transform* m_transform;
private:
	ModelRender m_modelRender;
	PhysicsStaticObject m_Object;
	Player* m_player = nullptr;

};

