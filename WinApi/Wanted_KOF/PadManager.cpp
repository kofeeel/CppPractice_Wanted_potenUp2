#include "PadManager.h"
#include <Xinput.h>

#pragma comment(lib, "XInput.lib")

HRESULT PadManager::Init()
{
	ButtonUp.set();		// true로 세팅.
	ButtonDown.reset();	// false로 세팅.
    return S_OK;
}

void PadManager::Release()
{
	Singleton::ReleaseInstance();
}

bool PadManager::IsOnceButtonDown(int button)
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // 구조체 초기화

	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// 버튼 입력 처리
		if (state.Gamepad.wButtons & button)
		{
			if (false == ButtonDown[button])
			{
				ButtonDown[button] = true;
				return true;
			}
		}

		else
		{
			ButtonDown[button] = false;
		}
	}
    return false;
}

bool PadManager::IsOnceButtonUp(int button)
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // 구조체 초기화

	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// 버튼 입력 처리
		if (state.Gamepad.wButtons & button)
		{
			ButtonUp[button] = false;
		}

		else
		{
			if (false == ButtonUp[button]) // 이중 체크하는 이유 -> 사람이 누르는 거랑 컴퓨터가 체크하는 거랑 차이가 있어서 동기화 느낌으로
			{
				ButtonUp[button] = true;
				return true;
			}
		}
	}
	return false;
}

bool PadManager::IsStayButtonDown(int button)
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // 구조체 초기화
	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// 버튼 입력 처리
		if (state.Gamepad.wButtons & button)
		{
			return true;
		}
	}

	return false;
}

void PadManager::SetVibration(WORD leftMotor, WORD rightMotor)
{
    XINPUT_VIBRATION vibration;
    ZeroMemory(&vibration, sizeof(XINPUT_VIBRATION));

    vibration.wLeftMotorSpeed = leftMotor;  // 왼쪽 모터 강도 (0~65535)
    vibration.wRightMotorSpeed = rightMotor; // 오른쪽 모터 강도 (0~65535)

    XInputSetState(0, &vibration);
}

void PadManager::GetControllerState()
{

	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // 구조체 초기화

	// Xbox 컨트롤러 0번(첫 번째 컨트롤러) 입력 상태 가져오기
	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// 버튼 입력 처리
		if (state.Gamepad.wButtons & BUTTON_A)
		{
			std::cout << "A 버튼이 눌렸습니다.\n";
		}

		if (state.Gamepad.wButtons & BUTTON_B)
		{
			// std::cout << "B 버튼이 눌렸습니다.\n";
		}

		if (state.Gamepad.wButtons & BUTTON_X)
		{
			//  std::cout << "X 버튼이 눌렸습니다.\n";
		}

		if (state.Gamepad.wButtons & BUTTON_Y)
		{
			//  std::cout << "Y 버튼이 눌렸습니다.\n";
		}

		if (state.Gamepad.wButtons & PAD_UP)
		{
			// std::cout << "Up 버튼이 눌렸습니다.\n";
		}

		if (state.Gamepad.wButtons & PAD_DOWN)
		{
			// std::cout << "Down 버튼이 눌렸습니다.\n";
		}

		if (state.Gamepad.wButtons & PAD_LEFT)
		{
			// std::cout << "Left 버튼이 눌렸습니다.\n";
		}

		if (state.Gamepad.wButtons & PAD_RIGHT)
		{
			std::cout << "Right 버튼이 눌렸습니다.\n";
		}

		//// 아날로그 스틱 값 출력
		//std::cout << "왼쪽 스틱: X=" << state.Gamepad.sThumbLX << ", Y=" << state.Gamepad.sThumbLY << "\n";
		//std::cout << "오른쪽 스틱: X=" << state.Gamepad.sThumbRX << ", Y=" << state.Gamepad.sThumbRY << "\n";

		//// 트리거 값 출력
		//std::cout << "LT: " << (int)state.Gamepad.bLeftTrigger << "   RT: " << (int)state.Gamepad.bRightTrigger << "\n";
	}

	else
	{
		//std::cout << "Xbox 컨트롤러를 찾을 수 없습니다.\n";
	}
    
}
