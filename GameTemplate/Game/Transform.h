#pragma once

class Transform : public Noncopyable
{
public:
	Transform();
	~Transform();
	bool Start();
	void Update();

	void SetParent(Transform* parent) {
		m_parent = parent;
	}

	void SetLocalPosition(Vector3 position) {
		m_localPosition = position;
	}
	void SetLocalScale(Vector3 scale) {
		m_localScale = scale;
	}
	void SetLocalRotation(Quaternion rotation) {
		m_localRotation = rotation;
	}


	const Vector3 GetPosition() {
		return m_position;
	}
	const Vector3 GetScale() {
		return m_scale;
	}
	const Quaternion GetRotation() {
		return m_rotation;
	}

	const Vector3 GetLocalPosition() {
		return m_localPosition;
	}
	const Vector3 GetLocalScale() {
		return m_localScale;
	}
	const Quaternion GetLocalRotation() {
		return m_localRotation;
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