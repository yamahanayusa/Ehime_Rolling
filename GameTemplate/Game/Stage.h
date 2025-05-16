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
	///// <summary>
	///// 座標を設定する
	///// </summary>
	///// <param name="position">座標</param>
	//void SetPosition(const Vector3& position)
	//{
	//	m_position = position;
	//	m_modelRender.SetPosition(m_position);
	//}
	///// <summary>
	///// 回転を設定する
	///// </summary>
	///// <param name="rotation">回転</param>
	//void SetRotation(const Quaternion& rotation)
	//{
	//	m_rotation = rotation;
	//	m_modelRender.SetRotation(m_rotation);
	//}
	///// <summary>
	///// 大きさを設定する
	///// </summary>
	///// <param name="scale">大きさ</param>
	//void SetScale(const Vector3& scale)
	//{
	//	m_scale = scale;
	//	m_modelRender.SetScale(m_scale);
	//}

	Vector3	m_scale = Vector3::One;//大きさ。
	//回転を設定する
	Quaternion addRot;
	Quaternion addLot;
	Transform* m_transform;
private:
	ModelRender m_modelRender;
	//Vector3 m_position;
	//Quaternion m_rotation;
	PhysicsStaticObject m_Object;
	Player* m_player = nullptr;
};
