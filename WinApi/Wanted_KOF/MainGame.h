#pragma once
#include "GameObject.h"

class Image;
class BattleManager;
class SelectUI;

const int P1IDX = 0;
const int P2IDX = 1;

class MainGame : public GameObject
{
public:
	enum class GameState
	{
		CharacterSelect,
		Battle,
		RoundWait,
	};

private:
	HDC hdc;
	PAINTSTRUCT ps;
	HANDLE hTimer;
	int mousePosX = 0, mousePosY = 0;
	
	FPOINT mousePos;
	wchar_t szText[128];

	Image* backBuffer;
	Image* backGround;

	GameState state;
	BattleManager* battleManager;
	SelectUI* selectUI;
	

	class Character* character;

public:
	void Init();	// override (�θ�Ŭ������ ���� �Լ��̸�, ������ �ٸ��� �����ϰ� ���� ��)
					// <-> overload (���� �Լ� �̸�, �Ű����� Ÿ�԰� ������ �ٸ��� �ٸ� �Լ��� ó��)
	void Release();	
	void Update();	
	void Render(HDC hdc);

	void SelectCharacter();
	void BattleStart();
	void RoundEndCheck();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	MainGame();
	~MainGame();
};

