#include <windows.h>
#include <iostream>

HINSTANCE g_hinstance; // 프로그램 인스턴스 핸들
HWND g_hWnd;		   // 윈도우 핸들
LPCWSTR g_lpszClassName = (LPCWSTR)TEXT("윈도우 API 사용하기"); // LPSTR 은 char형 포인터

enum class ShapeType : uint8_t
{
	None,
	Nemo,
	Star
};
struct BeingStar
{
	POINT pt;
	ShapeType type;
	int size;
};
/*
	1. 자동차 그리기 (함수화)
	2. a, d키로 움직이기
	3. 네모 or 동그라미를 그리고 마우스로 드래그& 드랍 구현
	4. 별이 되어라!
		
		
		1.   바닥에 네모 10개를 그린다.
		2. 마우스 드래그를 통해 위로 이동
		3. 특정 높이 이상 위치 감지
		4. 드랍을 하면 네모 -> 별 모양으로 바뀐다.

		left, right, top , bottom 


	5. 제어권이 있는 상자 구현  (w,a,s,d키로 움직임)
		5-1 큰 상자 두개 , 작은 상자 한개가 존재
		5-2 큰 상자 안에는 작은 상자가 들어있다. (제어권이 있는 상자)
		5-3 작은 상자는 큰 상자를 벗어날 수 없다.
		5-4 큰 상자끼리 부딪히면 작은상자가 큰 상자에게 넘어간다.(제어권이 넘어감)
*/
//구조체 만들어서
//직사각형 인지 별이될건지 체크


//좌상단 기준
void RenderRect(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}
// 중심을 기준으로 네모를 그리는 함수
void RenderRectAtCenter(HDC hdc, int centerX, int centerY, int width, int height)
{
	int left = centerX - width / 2;
	int top = centerY - height / 2;
	int right = centerX + width / 2;
	int bottom = centerY + height / 2;
	Rectangle(hdc, left, top, right, bottom);
}

void RenderEllipse(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}
// 중심을 기준으로 원을 그리는 함수
void RenderEllipseAtCenter(HDC hdc, int centerX, int centerY, int width, int height)
{
	int left = centerX - width / 2;
	int top = centerY - height / 2;
	int right = centerX + width / 2;
	int bottom = centerY + height / 2;
	Ellipse(hdc, left, top, right, bottom);
}

// 자동차를 그리는 함수 (중심 기반)
void RenderCar(HDC hdc, int posX, int posY)
{
	// 자동차 몸체 (가운데 정렬된 네모)
	RenderRectAtCenter(hdc, posX, posY, 200, 50);

	// 자동차 윗부분 창 (가운데 정렬된 작은 네모)
	RenderRectAtCenter(hdc, posX, posY - 30, 100, 50);

	// 바퀴 (가운데 정렬된 원 2개)
	RenderEllipseAtCenter(hdc, posX - 50, posY + 30, 50, 50);
	RenderEllipseAtCenter(hdc, posX + 50, posY + 30, 50, 50);
}

void RenderStar(HDC hdc, int posX, int posY)
{
	MoveToEx(hdc, posX + 60, posY + 20, NULL);
	LineTo(hdc, posX - 60, posY + 20);
	LineTo(hdc, posX + 40, posY - 60);
	LineTo(hdc, posX , posY + 60);
	LineTo(hdc, posX - 40 , posY - 60);
	LineTo(hdc, posX + 60, posY + 20);
}

bool RectInRect(RECT rec1, RECT rec2)
{
	if ((rec1.right < rec2.left) || (rec1.left > rec2.right) || (rec1.top > rec2.bottom) || (rec1.bottom > rec2.top))
	{
		return false;
	}
	return true;
}

void CheckSmallRect(RECT& rec1, RECT& rec2)
{
	bool isIn = RectInRect(rec1, rec2);
	if (isIn)
	{
		reset
	}
}

void RenderRect(HDC hdc, int x, int y, int width, int height);
void RenderRectAtCenter(HDC hdc, int centerX, int centerY, int width, int height);
void RenderEllipse(HDC hdc, int x, int y, int width, int height);
void RenderEllipseAtCenter(HDC hdc, int centerX, int centerY, int width, int height);
void RenderCar(HDC hdc, int posX, int posY);
bool PointInRect(POINT ptMouse, RECT rc); //ptInRect
void UpdateRect(RECT& rc, POINT pt);
void RenderStar(HDC hdc, int posX, int posY);
bool RectInRect(RECT rec1, RECT rec2);
void InitializeRect(RECT rec1, RECT rec2);

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	g_hinstance = hinstance;
	//윈도우를 생성하기위해 필요한 데이터 셋팅
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //색깔 지정
	wndClass.hCursor = LoadCursor(g_hinstance, IDC_ARROW);
	wndClass.hIcon = LoadIcon(g_hinstance, IDI_APPLICATION);
	wndClass.hInstance = g_hinstance;
	wndClass.lpfnWndProc = WndProc;		//함수의 이름은 메모리 주소이다. 함수는 같은클래스끼리 공유한다. //인스턴스에서 생성한 변수는 아님
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = g_lpszClassName;
	wndClass.style = CS_HREDRAW | CS_VREDRAW; // |: 비트연산자 ||: 논리연산자

	RegisterClass(&wndClass);

	g_hWnd = CreateWindow(g_lpszClassName, g_lpszClassName, WS_OVERLAPPEDWINDOW, 50, 50, 1080, 720,
		NULL, NULL, g_hinstance, NULL); //핸들을 저장
	if (ShowWindow(g_hWnd, nCmdShow))
	{

	}
	else
	{

	}

	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam; // 오류여부에 대한 값이 wParam에 전달

}


bool PointInRect(POINT ptMouse, RECT rc)
{
	if (ptMouse.x < rc.left || ptMouse.x > rc.right
		|| ptMouse.y < rc.top || ptMouse.y > rc.bottom)
	{
		return false;
	}
	return true;
}

void UpdateRect(RECT& rc, POINT pt)
{
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;
	
	rc.left = pt.x - (width / 2);
	rc.right = rc.left + width;
	rc.top = pt.y - (height / 2);
	rc.bottom = rc.top + height;
}
LRESULT WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc{};

	static int mousePosX = 0, mousePosY = 0;
	static int dan = 0;
	static int carPosX = 250; 
	static int posX = 0, posY = 0;
	static bool isGrab = false;
	static POINT pt;
	wchar_t szText[128];
	static BeingStar stars[10];
	static int selectedIndex = -1;
	static RECT rec{ 10, 10, 110, 110 };
	static RECT big1{ 300, 300, 400, 400 };
	static RECT big2{ 900, 900, 1000, 1000 };
	static RECT smallR{500, 500, 600, 600};
	static RECT destroyer{50,50,150,150};
	static int inputX;
	static int inputY;
	//static 변수: 함수 내에서 선언
	//데이터 영역에 메모리가 할당(전역변수와 같음)
	//프로그램 종료시 메모리 해제
	//해당 함수안에서만 접근 가능

	switch (iMessage)
	{
	case WM_CREATE:
		for (int i = 0; i < 10; i++)
		{
			stars[i].type = ShapeType::Nemo;
			stars[i].pt = POINT{ 50 + i * 60,  600 };
			stars[i].size = 50;
		}
	case WM_KEYDOWN:
		//wasd로 움직임
		UpdateRect(big1, POINT{ inputX, inputY });

		switch (wParam)
		{
		case 'W': case 'w':
			inputY -= 30;
			break;
		case 'A': case 'a':
			inputX -= 30;
			break;
		case 'S': case 's':
			inputY += 30;
			break;
		case 'D': case 'd':
			inputX += 30;
			break;
		}

		isGrab = PointInRect(pt,destroyer);

		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_LBUTTONDOWN:
		mousePosX = LOWORD(lParam); // 1111 0000 상위 4비트
		mousePosY = HIWORD(lParam); // 0000 1111 하위 4비트 체크한다  마우스가져오기
		//마우스 정보 담기
		pt.x = mousePosX;
		pt.y = mousePosY;
		
		for (int i = 0; i < 10; i++)
		{	
			UpdateRect(rec, stars[i].pt);
			isGrab = PointInRect(pt, rec);
			if (isGrab)
			{
				selectedIndex = i;
				break;
			}
		}
		
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		selectedIndex - 1;
		isGrab = false;

		break;
	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);
		
		if (isGrab)
		{
			UpdateRect(rec, POINT{ mousePosX, mousePosY });
		}

		if (selectedIndex != -1)
		{
			stars[selectedIndex].pt.x = mousePosX;
			stars[selectedIndex].pt.y = mousePosY;
		}

		if (isGrab)
		{
			UpdateRect(destroyer, POINT{ mousePosX, mousePosY });

			for (int i = 0; i < 10; i++)
			{
				if (stars[i].type == ShapeType::None)
				{
					continue;
				}

				UpdateRect(rec, stars[i].pt);
				if (RectInRect(destroyer, rec))
				{
					stars[i].type = ShapeType::None;
				}
			}
		}
		InvalidateRect(g_hWnd, NULL, true);
		break;
	case WM_PAINT:
		//TODO : 자체 로직 추가
		hdc = BeginPaint(g_hWnd, &ps);

		//그리기 위한 로직
		TextOut(hdc, 20, 20, TEXT("Hello, World!"), strlen("Hello, World!"));
		wsprintf(szText/* 문자열 공간 */, TEXT("Mouse X: %d, Y: %d")/* 형태 */,
			mousePosX/* 값1, 값2, ...*/, mousePosY);
		TextOut(hdc, 20, 60, szText, wcslen(szText));
#pragma region 직사각형출력
		/*if(isGrab)
			RenderEllipseAtCenter(hdc, mousePosX, mousePosY, 100, 100);
		else
			RenderEllipseAtCenter(hdc, posX, posY, 100, 100);*/
		/*for (int i = 0; i < 10; i++)
		{
			if (stars[i].type == ShapeType::None)
			{
				continue;
			}
			else if (stars[i].type == ShapeType::Nemo)
			{
				RenderRectAtCenter(hdc, stars[i].pt.x, stars[i].pt.y, stars[i].size, stars[i].size);
			}
			else
			{
				RenderStar(hdc, stars[i].pt.x, stars[i].pt.y);
			}
		}*/
		
		/*Rectangle(hdc, destroyer.left, destroyer.top, destroyer.right, destroyer.bottom);*/
		/*destroyRect(rec, destroyer);*/
#pragma endregion

		if
		Rectangle(hdc, big1.left, big1.top, big1.right, big1.bottom);
		Rectangle(hdc, big2.left, big2.top, big2.right, big2.bottom);
		Rectangle(hdc, smallR.left, smallR.top, smallR.right, smallR.bottom);
		
		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:
		
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
