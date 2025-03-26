#pragma once
#include "config.h"

#include "GameObject.h"

#define MAX_ROUND_WIN 2

#define PLAYER1_POS_X 50
#define PLAYER1_POS_Y 500
#define PLAYER2_POS_X 400
#define PLAYER2_POS_Y 50

class Player;
class BattleUI;

class BattleManager : public GameObject
{
public:
	BattleUI* ui;

	Player* player1;
	Player* player2;

	int p1Win;
	int p2Win;
	int time;
	int elapsedTime;

	clock_t start;
	clock_t finish;
	double duration;

public:
	void Init() override;
	void Update() override;
	void Render(HDC hdc) override;
	void Release() override;

	void AddCommand(int playerIdx, Command cmd);

	void SelectCharacter(int playerIdx, CharacterName name);
	bool RoundEndCheck();

	void RoundStart();

	BattleManager();
	~BattleManager();

};

