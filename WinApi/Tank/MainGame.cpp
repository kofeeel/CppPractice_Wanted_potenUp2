#include "MainGame.h"
#include "Tank.h"

/*
	�ǽ�1. �̻��� �ѹ� ���
	�ǽ�2. �̻��� ������ ���
	�ǽ�3. ��ų��1 (360�� �̻���) ���
	�ǽ�4. ��ų��2 (��ü ��ȹ) ���
*/

void MainGame::Init()
{
	tank = new Tank;
	tank->Init();
}

void MainGame::Release()
{
	if (tank)
	{
		tank->Release();
		delete tank;
	}
}

void MainGame::Update()
{
	if (tank)	tank->Update();  
	
}

void MainGame::Render(HDC hdc)
{
	wsprintf(szText, TEXT("Mouse X : %d, Y : %d"), mousePosX, mousePosY);
	TextOut(hdc, 20, 60, szText, wcslen(szText));

	if (tank)	tank->Render(hdc);
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_CREATE:
		hTimer = (HANDLE)SetTimer(hWnd, 0, 10, NULL); // 100ms(0.1��)���� Ÿ�̸Ӱ� ȣ�� 
		break;
	case WM_TIMER:
		this->Update(); //���� ������Ʈ 
		InvalidateRect(g_hWnd, NULL, true); //ȭ�� �ٽ� �׸��� ��û
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'a': case 'A':
			tank->RotateBarrel(DEG_TO_RAD(5));
			break;
		case 'd': case 'D':
			tank->RotateBarrel(DEG_TO_RAD(-5));
			break;
		case 'q': case 'Q':
			
			break;
		case VK_SPACE:
			tank->Fire();
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);
		break;
	case WM_LBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);

		InvalidateRect(g_hWnd, NULL, true);
		break;
	case WM_PAINT:
		hdc = BeginPaint(g_hWnd, &ps);

		this->Render(hdc);

		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 0);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}
