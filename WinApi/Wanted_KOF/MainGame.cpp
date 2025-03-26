#include "MainGame.h"
#include "KeyManager.h"
#include "PadManager.h"
#include "CommonFunction.h"
#include "BattleManager.h"
#include "SelectUI.h"
#include "Character.h"
#include "CollisionManager.h"
#include "Image.h"

void MainGame::Init()
{
	backBuffer = new Image();
	if (FAILED(backBuffer->Init(WINSIZE_X, WINSIZE_Y)))
	{
		MessageBox(g_hWnd, TEXT("back buffer init failed¨"), TEXT("Error"), MB_OK);
	}

	KeyManager::GetInstance()->Init();
	PadManager::GetInstance()->Init();

	backBuffer = new Image;
	backBuffer->Init(WINSIZE_X, WINSIZE_Y);

	battleManager = new BattleManager;
	battleManager->Init();

	selectUI = new SelectUI;
}

void MainGame::Release()
{
	if (selectUI)
	{
		delete selectUI;
	}

	if (backBuffer)
	{
		backBuffer->Release();
		delete backBuffer;
		backBuffer = nullptr;
	}
}

void MainGame::Update()
{
	if (state == GameState::CharacterSelect)
	{
		SelectCharacter();
	}
	else if (state == GameState::Battle)
	{
		this->battleManager->RoundStart();
		BattleStart();
	}
	else
	{
		this->battleManager->Update();
		RoundEndCheck();
	}

	CollisionManager::GetInstance()->Update();

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	if (state == GameState::CharacterSelect)
	{
		selectUI->Render(hBackBufferDC);
	}
	else if (state == GameState::RoundWait)
	{
		battleManager->Render(hBackBufferDC);
	}

	backBuffer->Render(hdc);

}

void MainGame::SelectCharacter()
{
	if (selectUI)
	{
		if (!selectUI->GetPlayerIsSelect(P1IDX))	
		{
			if (KeyManager::GetInstance()->IsOnceKeyDown('A'))
			{
				selectUI->Move(P1IDX, -1);
			}
			else if (KeyManager::GetInstance()->IsOnceKeyDown('D'))
			{
				selectUI->Move(P1IDX, 1);
			}
			else if (KeyManager::GetInstance()->IsOnceKeyDown('Z'))
			{
				battleManager->SelectCharacter(P1IDX, selectUI->Select(P1IDX));
			}
		}

		if (!selectUI->GetPlayerIsSelect(P2IDX))	
		{
			if (PadManager::GetInstance()->IsOnceButtonDown(PAD_LEFT))
			{
				selectUI->Move(P2IDX, -1);
			}
			else if (PadManager::GetInstance()->IsOnceButtonDown(PAD_RIGHT))
			{
				selectUI->Move(P2IDX, 1);
			}
			else if (PadManager::GetInstance()->IsOnceButtonDown(BUTTON_A))
			{
				battleManager->SelectCharacter(P2IDX, selectUI->Select(P2IDX));
			}

			if (KeyManager::GetInstance()->IsOnceKeyDown(VK_NUMPAD4))
			{
				selectUI->Move(P2IDX, -1);
			}
			else if (KeyManager::GetInstance()->IsOnceKeyDown(VK_NUMPAD6))
			{
				selectUI->Move(P2IDX, 1);
			}
			else if (KeyManager::GetInstance()->IsOnceKeyDown('U'))
			{
				battleManager->SelectCharacter(P2IDX, selectUI->Select(P2IDX));
			}
		}
	}

	if (selectUI->GetPlayerIsSelect(P1IDX) && selectUI->GetPlayerIsSelect(P2IDX)) 		// ÀÓ½Ã ÄÚµå
	{
		state = GameState::Battle;
		selectUI->Reset();
	}
}

void MainGame::BattleStart()
{
	state = GameState::RoundWait;
}

void MainGame::RoundEndCheck()
{
	if (battleManager->p1Win >= 2 || battleManager->p2Win >= 2)
	{
		state = GameState::CharacterSelect;
		return;
	}

#pragma region P1 Input
	if (KeyManager::GetInstance()->IsStayKeyDown('W'))			// Stay
	{
		battleManager->AddCommand(P1IDX, Command::Up);
	}
	else if (KeyManager::GetInstance()->IsStayKeyDown('A'))
	{
		battleManager->AddCommand(P1IDX, Command::Left);
	}
	else if (KeyManager::GetInstance()->IsStayKeyDown('S'))
	{
		battleManager->AddCommand(P1IDX, Command::Down);
	}
	else if (KeyManager::GetInstance()->IsStayKeyDown('D'))
	{
		battleManager->AddCommand(P1IDX, Command::Right);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('Z'))		// Once
	{
		battleManager->AddCommand(P1IDX, Command::A);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('X'))	
	{
		battleManager->AddCommand(P1IDX, Command::B);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('C'))
	{
		battleManager->AddCommand(P1IDX, Command::X);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('V'))
	{
		battleManager->AddCommand(P1IDX, Command::Y);
	}
#pragma endregion

#pragma region P2 Input
	if (PadManager::GetInstance()->IsStayButtonDown(PAD_UP))			// Stay
	{
		battleManager->AddCommand(P2IDX, Command::Up);
	}
	else if (PadManager::GetInstance()->IsStayButtonDown(PAD_LEFT))
	{
		battleManager->AddCommand(P2IDX, Command::Left);
	}
	else if (PadManager::GetInstance()->IsStayButtonDown(PAD_DOWN))
	{
		battleManager->AddCommand(P2IDX, Command::Down);
	}
	else if (PadManager::GetInstance()->IsStayButtonDown(PAD_RIGHT))
	{
		battleManager->AddCommand(P2IDX, Command::Right);
	}
	else if (PadManager::GetInstance()->IsOnceButtonDown(BUTTON_A))		// Once
	{
		battleManager->AddCommand(P2IDX, Command::A);
	}
	else if (PadManager::GetInstance()->IsOnceButtonDown(BUTTON_B))	
	{
		battleManager->AddCommand(P2IDX, Command::B);
	}
	else if (PadManager::GetInstance()->IsOnceButtonDown(BUTTON_X))
	{
		battleManager->AddCommand(P2IDX, Command::X);
	}
	else if (PadManager::GetInstance()->IsOnceButtonDown(BUTTON_Y))
	{
		battleManager->AddCommand(P2IDX, Command::Y);
	}

	// ÀÓ½Ã
	if (KeyManager::GetInstance()->IsStayKeyDown(VK_NUMPAD8))			// Stay
	{
		battleManager->AddCommand(P1IDX, Command::Up);
	}
	else if (KeyManager::GetInstance()->IsStayKeyDown(VK_NUMPAD4))
	{
		battleManager->AddCommand(P1IDX, Command::Left);
	}
	else if (KeyManager::GetInstance()->IsStayKeyDown(VK_NUMPAD5))
	{
		battleManager->AddCommand(P1IDX, Command::Down);
	}
	else if (KeyManager::GetInstance()->IsStayKeyDown(VK_NUMPAD6))
	{
		battleManager->AddCommand(P1IDX, Command::Right);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('U'))		// Once
	{
		battleManager->AddCommand(P1IDX, Command::A);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('I'))
	{
		battleManager->AddCommand(P1IDX, Command::B);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('O'))
	{
		battleManager->AddCommand(P1IDX, Command::X);
	}
	else if (KeyManager::GetInstance()->IsOnceKeyDown('P'))
	{
		battleManager->AddCommand(P1IDX, Command::Y);
	}
#pragma endregion
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_CREATE:
		hTimer = (HANDLE)SetTimer(hWnd, 0, 10, NULL);

		break;
	case WM_TIMER:
		this->Update();
		break;
	case WM_KEYDOWN:
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_MOUSEMOVE:
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
