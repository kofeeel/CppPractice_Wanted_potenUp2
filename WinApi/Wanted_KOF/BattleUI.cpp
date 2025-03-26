#include "BattleUI.h"
#include "CommonFunction.h"

#define HPBAR_MAX_WIDTH 200
#define HPBAR_MAX_HEIGHT 40

#define P1_HPBAR_POS_X 100
#define P1_HPBAR_POS_Y 50

#define P2_HPBAR_POS_X 400
#define P2_HPBAR_POS_Y 50

#define P1_NAME_POS_X 100
#define P1_NAME_POS_Y 100

#define P2_NAME_POS_X 400
#define P2_NAME_POS_Y P1_NAME_POS_Y

#define TIME_POS_X 330
#define TIME_POS_Y 80

void BattleUI::Render(HDC hdc)
{
	Rectangle(hdc, 0, 0, 1000, 500);

	// 두 캐릭터의 이름 출력.
	TextOutW(hdc, P1_NAME_POS_X, P1_NAME_POS_Y, p1Name.c_str(), p1Name.length());
	TextOutW(hdc, P2_NAME_POS_X, P2_NAME_POS_Y, p2Name.c_str(), p2Name.length());

	// 두 캐릭터의 HP 출력.
	
	// 체력바 테두리
	RenderRect(hdc, P1_HPBAR_POS_X, P1_HPBAR_POS_Y, HPBAR_MAX_WIDTH, HPBAR_MAX_HEIGHT);
	RenderRect(hdc, P2_HPBAR_POS_X, P2_HPBAR_POS_Y, HPBAR_MAX_WIDTH, HPBAR_MAX_HEIGHT);

	// 체력바 내부에 실제 체력 표현
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hpBrush);
	RenderRect(hdc, P1_HPBAR_POS_X, P1_HPBAR_POS_Y, HPBAR_MAX_WIDTH * (p1HP / 100.0), HPBAR_MAX_HEIGHT);
	RenderRect(hdc, P2_HPBAR_POS_X, P2_HPBAR_POS_Y, HPBAR_MAX_WIDTH * (p2HP / 100.0), HPBAR_MAX_HEIGHT);
	
	//시간
	TextOutW(hdc, TIME_POS_X, TIME_POS_Y, time.c_str(), time.length());
	
	SelectObject(hdc, oldBrush);
}

void BattleUI::Release()
{

}

void BattleUI::Update()
{

}

void BattleUI::Init()
{
	hpBrush = CreateSolidBrush(RGB(255,0,0));


}

void BattleUI::SetP1Name(wstring name)
{
	this->p1Name = name;
}

void BattleUI::SetP2Name(wstring name)
{
	this->p2Name = name;
}

void BattleUI::AddPlayerWin(int playerIndex)
{
	if (0 == playerIndex)
	{
		this->p1Win ++;
	}
	else 
	{
		this->p2Win++;
	}
}

void BattleUI::SetPlayerHP(int playerIndex, int hp)
{
	if (0 == playerIndex)
	{
		this->p1HP = hp;
	}
	else
	{
		this->p2HP = hp;
	}
}

void BattleUI::SetTime(int time)
{
	this->time = std::to_wstring(time);
}

void BattleUI::SetWin(int playerIndex, int win)
{
	0 == playerIndex? p1Win = win : p2Win = win;
}
