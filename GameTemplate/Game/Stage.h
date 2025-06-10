#pragma once

class Player;
class Transform;

class Stage : public IGameObject
{
public:
	Stage();
	~Stage();
	//スタート
	bool Start();
	//アップデート
	void Update();
	//回転処理
	void Rotation();
	//レンダー
	void Render(RenderContext& rc);

	Transform* GetTransform()
	{
		return m_transform;
	}

	/// <summary>
	/// ワールド行列を取得する
	/// </summary>
	Matrix GetWorldMatrix() const
	{
		return m_modelRender.GetWorldMatrix(0);
	}

	Vector3	m_scale = Vector3::One;//大きさ。
	//回転を設定する
	Quaternion addRot;
	Quaternion addLot;
	Transform* m_transform;
private:
	ModelRender m_modelRender;
	PhysicsStaticObject m_Object;
	Player* m_player = nullptr;
};
