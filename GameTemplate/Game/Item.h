#include "Transform.h"  

class Transform;
class Player;
class Score;
class Timer;
class Stage;

enum Kind{
	SCORE,
	BUFF
};

namespace  MikanStetus {
	const int SCORE = 100;					//みかんのスコア
}

namespace  JakotenStetus {
	const float BUFF_MULTIPIER = 2.0f;		//バフの倍率。
	const float BUFF_TIME = 10.0f;			//バフの継続時間。
}

namespace  KiwiStetus {
	const int SCORE = 200;					//キウイのスコア
}

class Itembase :public IGameObject
{
public:
	Itembase();
	~Itembase();

	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) ;
	Transform* GetTransform()
	{
		return m_transform;
	}

    float m_flyUpTimer = 0.0f; // 上昇時間を追跡するタイマー

	virtual void AddStart() = 0;
	Vector3					m_flyVelocity = Vector3::Zero; /*{ 0.0f,0.0f,0.0f };*/
	Vector3					m_velocity = Vector3::Zero; // 上昇速度ベクトル（初期化追加）
	Stage* m_stage=nullptr;
	bool m_isFlying = false; // ← 初期値をfalseに変更

	/// <summary>
	/// ステータスを設定。
	/// </summary>
	/// <param name="kind">アイテムの種類。</param>
	/// <param name="data">スコアなら加算するポイント、バフなら効果時間を設定。</param>
	/// <param name="filePath">モデルレンダーのファイルパスを設定。</param>
	/// <returns></returns>
	const void SetStatus(const Kind& kind,const int& data, const char* filePath){
		m_itemKind = kind;

		switch (m_itemKind) {
		case Kind::SCORE:
			m_itemScore = data;
			break;
		case Kind::BUFF:
			m_buffTimer = data;
			break;
		}

		m_modelRender.Init(filePath);
		m_modelRender.SetScale(1.0f, 1.0f, 1.0f);
	};
private:
	void ItemDistance();
	void Move();
	void PlaySE();
	void ItemFly();
protected:
	Kind	m_itemKind = SCORE;
	int		m_itemScore = 0;
	float	m_buffTimer = 0;	//バフの経過時間。
	bool	m_isGet = false;	//プレイヤーがじゃこ天を獲得したかどうか。
	ModelRender			m_modelRender;						//モデルレンダ―。

private:
	Score* m_score = nullptr;
	Timer* m_timer = nullptr;
	Player* m_player = nullptr;
	Transform* m_transform = nullptr;

	bool m_isCollected = false;				//アイテム取得済みかどうかのフラグ
	bool m_isSE = false;
};

class Mikan :public Itembase
{
public:
	Mikan() {};
	~Mikan() {};
	void AddStart() override {
		SetStatus(SCORE, MikanStetus::SCORE,("Assets/modelData/mikan.tkm"));
	};
private:
};

class Jakoten : public Itembase
{
	Jakoten() {};
	~Jakoten() {};
	void AddStart() override {
		SetStatus(BUFF, JakotenStetus::BUFF_TIME ,("Assets/modelData/Jakoten.tkm"));
	};

private:

};

class Kiwi :public Itembase
{
	Kiwi() {};
	~Kiwi() {};
	void AddStart() override {

		SetStatus(SCORE, KiwiStetus::SCORE, ("Assets/modelData/Kiwi/Kiwi.tkm"));
	};

private:
};