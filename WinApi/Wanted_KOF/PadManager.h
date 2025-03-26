#pragma once
#include <bitset>
#include <map>
#include "config.h"
#include "Singleton.h"

#define MAX_KEY_COUNT 256

#define BUTTON_A                0x1000
#define BUTTON_B                0x2000
#define BUTTON_X                0x4000
#define BUTTON_Y                0x8000
#define PAD_UP					0x0001
#define PAD_DOWN				0x0002
#define PAD_LEFT				0x0004
#define PAD_RIGHT				0x0008

using namespace std;

enum ButtonType
{

};
class PadManager : public Singleton<PadManager>
{

private:
	bitset<INT_MAX> ButtonUp;
	bitset<INT_MAX> ButtonDown;
	map<int, float> ButtonPressingTime;

public:
	HRESULT Init();
	void Release();

	bool IsOnceButtonDown(int button);
	bool IsOnceButtonUp(int button);
	bool IsStayButtonDown(int button);
	//bool IsStayButtonDown(int button, float time); // InputTime

	void SetVibration(WORD leftMotor, WORD rightMotor);
	void GetControllerState();

	inline bool IsValidInput(int& button)
	{
		return (BUTTON_A == button || BUTTON_B == button || BUTTON_X == button ||BUTTON_Y == button ||
			PAD_DOWN == button || PAD_UP == button || PAD_LEFT == button || PAD_RIGHT == button);
	}

};