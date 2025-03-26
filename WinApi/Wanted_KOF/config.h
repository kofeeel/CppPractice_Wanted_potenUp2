// config.h

#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include "KeyManager.h"

using namespace std;

/*
	컴파일러에서 해당 코드를 뒤에 정의된 코드로 변경한다. 
*/
#define WINSIZE_X	1080
#define WINSIZE_Y	500
#define DEG_TO_RAD(degree) ((3.14 / 180.0) * degree)
#define RAD_TO_DEG(radian) ((180.0 / 3.14) * radian)
#define MAX_FRAME 21400000

typedef struct tagFPOINT
{
	float x;
	float y;
} FPOINT;

typedef struct _Ellipse
{
	int centerX;
	int centerY;
	int radius;
}CEllipse;

enum class CharacterName
{
	None, Mature, Ryo, Terry, K,
};

enum class Command
{
	Up,
	Down,
	Left,
	Right,
	A,
	B,
	X,
	Y
};

inline std::wstring toWCharacterName(CharacterName name)
{
	switch (name)
	{
	case CharacterName::Mature: return L"Mature";
	case CharacterName::Ryo:	return L"Ryo";
	case CharacterName::Terry:	return L"Terry";
	case CharacterName::K:		return L"K";
	default:
		break;
	}

	return std::wstring(L"Unknown");
}

inline std::string toCharacterName(CharacterName name)
{
	switch (name)
	{
	case CharacterName::Mature: return "Mature";
	case CharacterName::Ryo:	return "Ryo";
	case CharacterName::Terry:	return "Terry";
	case CharacterName::K:		return "K";
	default:					return "Unknown";
	}
}
/*
	extern 키워드 : 변수나 함수가 다른 파일에 정의되어 있다 라는
	사실을 알리는 키워드.
*/
extern HWND g_hWnd;
extern HINSTANCE g_hInstance;
