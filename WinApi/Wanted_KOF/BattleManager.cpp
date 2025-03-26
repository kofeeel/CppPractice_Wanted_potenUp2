#include "BattleManager.h"
#include "BattleUI.h"
#include "Player.h"

void BattleManager::Init()
{
	ui = new BattleUI();
	ui->Init();

	player1 = new Player();
	player1->Init();

	player2 = new Player();
	player2->Init();

	p1Win = 0;
	p2Win = 0;
	time = 0;
	elapsedTime = 0;

	start = clock();
	finish = 0;
	duration = 0;
}

void BattleManager::Update()
{
	if(nullptr != player1) player1->Update();
	if(nullptr != player2) player2->Update();

	// 흘러간 시간 계산해서 1초 될때마다 감소시키기.
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	if (1 + elapsedTime <= duration)
	{
		elapsedTime += 1;
		time--;
		
		ui->SetTime(time);
	}

	this->ui->SetPlayerHP(0, player1->GetHP());
	this->ui->SetPlayerHP(1, player2->GetHP());

	if (RoundEndCheck())
	{
		this->ui->SetWin(0, p1Win);
		this->ui->SetWin(0, p2Win);

		// 라운드가 종료되었다 누가 이겼나?
		if (MAX_ROUND_WIN <= p1Win)
		{
			//플레이어 1 승리.
		}

		if (MAX_ROUND_WIN <= p2Win)
		{
			// 플레이어 2 승리.
		}
	}
}

void BattleManager::Render(HDC hdc)
{
	if (nullptr != ui)
	{
		ui->Render(hdc);
	}

	if (nullptr != player1)
	{
		player1->Render(hdc);
	}
	if (nullptr != player2)
	{
		player2->Render(hdc);
	}
}

void BattleManager::Release()
{
	if (nullptr != player1)
	{
		player1->Release();
		delete player1;
		player1 = nullptr;
	}

	if (nullptr != player2)
	{
		player2->Release();
		delete player2;
		player2 = nullptr;
	}

	if (nullptr != ui)
	{
		ui->Release();
		delete ui;
		ui = nullptr;
	}
}

void BattleManager::AddCommand(int playerIdx, Command cmd)
{
	if (0 == playerIdx)
	{
		this->player1->AddCommand(cmd);
	}
	else if(1 == playerIdx)
	{
		this->player2->AddCommand(cmd);
	}
}

void BattleManager::SelectCharacter(int playerIdx, CharacterName name)
{
	if (0 == playerIdx)
	{
		this->player1->SelectCharacter(name);
		this->ui->SetP1Name(toWCharacterName(name));
	}
	else if(1 == playerIdx)
	{
		this->player2->SelectCharacter(name);

		this->ui->SetP2Name(toWCharacterName(name));
	}
}

bool BattleManager::RoundEndCheck()
{
	// 시간 체크, 캐릭터들 HP체크.
	//  1:1인 상황인데 두 캐릭터의 체력이 똑같다면? 추가시간 + 10초 (무한대)
	int p1HP = player1->GetHP();
	int p2HP = player2->GetHP();
	
	if (0 == time)
	{
		if (0 != p1HP && p1HP == p2HP)	// 둘다 0이면 큰일.
		{
			// 추가시간.
			time += 10;
			return false;	// 아직 끝나지 않았음.
		}

		// 0초가 되면 체력이 많은 플레이어의 승.
		if (p1HP < p2HP)
		{
			p2Win++;
		}
		else {
			p1Win++;
		}

		return true;	// 끝.
	}
	
	if (0 == p1HP && 0 == p2HP)
	{
		// 둘다 체력이 0이면 한판 더 시키고 싶긴한데.
		p1Win++;
		return true;
	}
	else if (0 == p1HP)
	{
		p2Win++;
		return true;
	}
	else if(0 == p2HP){
		p1Win++;
		return true;
	}

	return false;
}

void BattleManager::RoundStart()
{
	// 지나간 시간 확인용. 클래스로 빼기, 다양한 값들 초기화
	start = clock();
	finish = 0;
	duration = 0;
	elapsedTime = 0;

	time = 60;
	ui->SetTime(time);

	// 캐릭터 위치들 초기화
	player1->SetPos(FPOINT{PLAYER1_POS_X, PLAYER1_POS_Y});
	player2->SetPos(FPOINT{PLAYER2_POS_X, PLAYER2_POS_Y });

}

BattleManager::BattleManager()
: ui(nullptr), player1(nullptr), player2(nullptr)
{
	p1Win = 0;
	p2Win = 0;
	time = 0;
}

BattleManager::~BattleManager()
{
	if (ui)
	{
		ui->Release();
		delete ui;
		ui = nullptr;
	}
}
