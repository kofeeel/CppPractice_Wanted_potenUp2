#include "PadManager.h"
#include <Xinput.h>

#pragma comment(lib, "XInput.lib")

HRESULT PadManager::Init()
{
	ButtonUp.set();		// true�� ����.
	ButtonDown.reset();	// false�� ����.
    return S_OK;
}

void PadManager::Release()
{
	Singleton::ReleaseInstance();
}

bool PadManager::IsOnceButtonDown(int button)
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // ����ü �ʱ�ȭ

	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// ��ư �Է� ó��
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
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // ����ü �ʱ�ȭ

	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// ��ư �Է� ó��
		if (state.Gamepad.wButtons & button)
		{
			ButtonUp[button] = false;
		}

		else
		{
			if (false == ButtonUp[button]) // ���� üũ�ϴ� ���� -> ����� ������ �Ŷ� ��ǻ�Ͱ� üũ�ϴ� �Ŷ� ���̰� �־ ����ȭ ��������
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
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // ����ü �ʱ�ȭ
	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// ��ư �Է� ó��
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

    vibration.wLeftMotorSpeed = leftMotor;  // ���� ���� ���� (0~65535)
    vibration.wRightMotorSpeed = rightMotor; // ������ ���� ���� (0~65535)

    XInputSetState(0, &vibration);
}

void PadManager::GetControllerState()
{

	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE)); // ����ü �ʱ�ȭ

	// Xbox ��Ʈ�ѷ� 0��(ù ��° ��Ʈ�ѷ�) �Է� ���� ��������
	if (XInputGetState(0, &state) == ERROR_SUCCESS)
	{
		// ��ư �Է� ó��
		if (state.Gamepad.wButtons & BUTTON_A)
		{
			std::cout << "A ��ư�� ���Ƚ��ϴ�.\n";
		}

		if (state.Gamepad.wButtons & BUTTON_B)
		{
			// std::cout << "B ��ư�� ���Ƚ��ϴ�.\n";
		}

		if (state.Gamepad.wButtons & BUTTON_X)
		{
			//  std::cout << "X ��ư�� ���Ƚ��ϴ�.\n";
		}

		if (state.Gamepad.wButtons & BUTTON_Y)
		{
			//  std::cout << "Y ��ư�� ���Ƚ��ϴ�.\n";
		}

		if (state.Gamepad.wButtons & PAD_UP)
		{
			// std::cout << "Up ��ư�� ���Ƚ��ϴ�.\n";
		}

		if (state.Gamepad.wButtons & PAD_DOWN)
		{
			// std::cout << "Down ��ư�� ���Ƚ��ϴ�.\n";
		}

		if (state.Gamepad.wButtons & PAD_LEFT)
		{
			// std::cout << "Left ��ư�� ���Ƚ��ϴ�.\n";
		}

		if (state.Gamepad.wButtons & PAD_RIGHT)
		{
			std::cout << "Right ��ư�� ���Ƚ��ϴ�.\n";
		}

		//// �Ƴ��α� ��ƽ �� ���
		//std::cout << "���� ��ƽ: X=" << state.Gamepad.sThumbLX << ", Y=" << state.Gamepad.sThumbLY << "\n";
		//std::cout << "������ ��ƽ: X=" << state.Gamepad.sThumbRX << ", Y=" << state.Gamepad.sThumbRY << "\n";

		//// Ʈ���� �� ���
		//std::cout << "LT: " << (int)state.Gamepad.bLeftTrigger << "   RT: " << (int)state.Gamepad.bRightTrigger << "\n";
	}

	else
	{
		//std::cout << "Xbox ��Ʈ�ѷ��� ã�� �� �����ϴ�.\n";
	}
    
}
