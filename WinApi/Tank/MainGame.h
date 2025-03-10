#pragma once
#include "GameObject.h"

class Tank;
class MainGame : public GameObject
{
private:
	HDC hdc;   //handle device context, 출력에 필요한 정보를 가지는 데이터 구조체(좌표,색,굵기)등의 정보를 담고있다.
			   //HDC 는 DC의 정보를 저장하는 데이터 구조체의 위치를 알기위함, 하지만 포인터는 아니다.
	PAINTSTRUCT ps;  //그리기위한 정보
	HANDLE hTimer; 
	int mousePosX = 0, mousePosY = 0;
	wchar_t szText[128];
	Tank* tank; 

public:
	void Init();	
	void Release();	
	void Update();	
	void Render(HDC hdc);

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	MainGame();
	~MainGame();
};

