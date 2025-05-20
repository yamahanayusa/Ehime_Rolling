#pragma once

class Transform : public IGameObject
{
public:
	Transform();
	~Transform();
	bool Start();
	void Update();

	void SetParent(Transform* parent) {
		m_parent = parent;
	}

public:
	Transform*	m_parent = nullptr;
	
	Vector3		m_position;			//座標。
	Vector3		m_scale;			//拡縮。
	Vector3		m_localPosition;	//ローカル座標。
	Vector3		m_localScale;		//ローカル拡縮。

	Quaternion	m_rotation;			//回転。
	Quaternion	m_localRotation;	//ローカル回転。
};