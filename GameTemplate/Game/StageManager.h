#pragma once

class Kiwi;
class Stage;
class Mikan;
class Flag;
class Bumper;
class Jakoten;
class IceFloor;
class SandFloor;

class StageManager:public IGameObject
{
public:
	StageManager();
	~StageManager();
	bool Start();
	void Update();

	/// <summary>
	/// Level‚ÌInit
	/// </summary>
	/// <param name="falePath">LevelFilePath</param>
	void Init(const char* falePath);

private:
	Stage*		m_stage		= nullptr;
	Flag*		m_flag		= nullptr;
	Jakoten*	m_jakoten	= nullptr;
	IceFloor*	m_iceFloor	= nullptr;
	SandFloor*	m_sandFloor = nullptr;

	std::vector<Kiwi*> m_kiwi;
	std::vector<Mikan*> m_mikan;
	std::vector<Bumper*> m_bumper;

	LevelRender m_levelRender;
};

