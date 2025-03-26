#pragma once
#include "config.h"
#include "GameObject.h"

class BattleUI : public GameObject
{

public:
	// Name TestBox
	wstring p1Name;
	wstring p2Name;

	int p1HP;
	int p2HP;

	int p1Win;
	int p2Win;

	// int p1rage;
	// int p2rage;

	wstring time;	//60초 부터 시작해서 현재 남은 시간.

	HBRUSH hpBrush;

public:
	void Render(HDC hdc) override;
	void Release() override;
	void Update() override;
	void Init() override;

	void SetP1Name(wstring name);
	void SetP2Name(wstring name);

	void AddPlayerWin(int playerIndex);
	void SetPlayerHP(int playerIndex, int hp);
	void SetTime(int time);

	void SetWin(int playerIndex, int win);
	
};

