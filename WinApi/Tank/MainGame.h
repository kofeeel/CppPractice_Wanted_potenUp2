#pragma once
#include "GameObject.h"

class Tank;
class MainGame : public GameObject
{
private:
	HDC hdc;   //handle device context, ��¿� �ʿ��� ������ ������ ������ ����ü(��ǥ,��,����)���� ������ ����ִ�.
			   //HDC �� DC�� ������ �����ϴ� ������ ����ü�� ��ġ�� �˱�����, ������ �����ʹ� �ƴϴ�.
	PAINTSTRUCT ps;  //�׸������� ����
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

