#pragma once

//ばねカメラを使用したい場合は、SpringCameraをインクルードする。
#include "camera/SpringCamera.h"

//クラス宣言
class Player;

class GameCamera :public IGameObject
{
public:

	GameCamera();
	~GameCamera();
	//スタート
	bool Start();
	//アップデート
	void Update();
	Player* m_player = nullptr;//プレイヤー	
	Vector3 m_toCameraPos = Vector3::One;//カメラポス
	SpringCamera  m_springCamera;//ばねカメラ
};

