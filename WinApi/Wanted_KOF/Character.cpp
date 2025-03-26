#include "Character.h"
#include "CommonFunction.h"
#include "CollisionManager.h"

#include "KeyManager.h"
#include "Image.h"
#include <functional>


void Character::SetPos(const FPOINT pos)
{
	this->pos = pos;
	body->SetRect(GetRectAtCenter(pos.x, pos.y, width, height));
}

void Character::Init()
{
	divFrame = 8;
	pos.x = 0, pos.y = 0;
	hp = 100;
	moveSpeed = 3.0f;
	width = 50;
	height = 150;
	name = CharacterName::None;
	state = CharacterState::Idle;
	body = CollisionManager::GetInstance()->CreateCollisionRect(this, GetRectAtCenter(pos.x, pos.y, width, height));
	isAttacking = false;
	body->Bind(
		[&](GameObject* owner)
		{
			this->BodyCollisionDetect(owner);
		});

	//init 에서 공격별 이미지파일 위치를 때려박음.
	//Attack* WalkWeakUpperAttack = new Attack(/*해당공격의 애니메이션이 들어있는 파일경로*/);

	animIdle = new Image();
	if (FAILED(animIdle->Init(TEXT("image/Ryo/Ryo_Endle.bmp"), 2417, 300, 10, 1, true, RGB(255, 0, 255)))) //오른쪽으로 걷기
	{
		MessageBox(g_hWnd, TEXT("image/Ryo/Ryo_Endle.bmp 파일 로드에 실패"), TEXT("경고"), MB_OK);
	}

	animWalkBack = new Image();
	if (FAILED(animWalkBack->Init(TEXT("image/Ryo/Ryo_Smove_Back.bmp"), 1047, 305, 6, 1, true, RGB(255, 0, 255)))) //오른쪽으로 걷기
	{
		MessageBox(g_hWnd, TEXT("image/Ryo/Ryo_Smove_Back.bmp 파일 로드에 실패"), TEXT("경고"), MB_OK);
	}

	animWalkFront = new Image();
	if (FAILED(animWalkFront->Init(TEXT("image/Ryo/Ryo_Smove_Front.bmp"), 1097, 300, 6, 1, true, RGB(255, 0, 255)))) //오른쪽으로 걷기
	{
		MessageBox(g_hWnd, TEXT("image/Ryo/Ryo_Smove_Front.bmp 파일 로드에 실패"), TEXT("경고"), MB_OK);
	}

	animSitDown = new Image();
	if (FAILED(animWalkFront->Init(TEXT("image/Ryo/Ryo_Sit.bmp"), 903, 300, 4, 1, true, RGB(255, 0, 255)))) //오른쪽으로 걷기
	{
		MessageBox(g_hWnd, TEXT("image/Ryo/Ryo_Sit.bmp 파일 로드에 실패"), TEXT("경고"), MB_OK);
	}

	animJump = new Image();
	if (FAILED(animJump->Init(TEXT("image/Ryo/Ryo_Jump.bmp"), 4485, 730, 16, 1, true, RGB(255, 0, 255))))
	{
		MessageBox(g_hWnd, TEXT("image/Ryo/Ryo_Jump.bmp 파일 로드에 실패"), TEXT("경고"), MB_OK);
	}
	curAnim = animIdle;

	int radius = 5;
	int maxFrame = 3;
	Attack* WalkWeakUpperAttack = new Attack(L"image/Ryo/Ryo_Wpunch.bmp", 906, 300, maxFrame, 1, true, RGB(255, 0, 255));
	WalkWeakUpperAttack->Init(5, pos, radius);
	attackMap.insert({ AttackType::WalkWeakUpperAttack, WalkWeakUpperAttack });
	offSetMap.insert({ AttackType::WalkWeakUpperAttack, 0 });
	maxFrameMap[AttackType::WalkWeakUpperAttack] = maxFrame;

	maxFrame = 6;
	Attack* WalkStrongUpperAttack = new Attack(L"image/Ryo/Ryo_Spunch.bmp", 1791, 310, 6, 1, true, RGB(255, 0, 255));
	WalkStrongUpperAttack->Init(7, pos, radius);
	attackMap.insert({ AttackType::WalkStrongUpperAttack, WalkStrongUpperAttack });
	offSetMap.insert({ AttackType::WalkStrongUpperAttack, +10 });
	maxFrameMap[AttackType::WalkStrongUpperAttack] = maxFrame;

	Attack* WalkWeakUnderAttack = new Attack(L"image/Ryo/Ryo_Middlekick.bmp", 2485, 360, 6, 1, true, RGB(255, 0, 255));
	WalkWeakUnderAttack->Init(10, pos, radius);
	attackMap.insert({ AttackType::WalkWeakUnderAttack, WalkWeakUnderAttack });
	offSetMap.insert({ AttackType::WalkWeakUnderAttack, -60 });
	maxFrameMap[AttackType::WalkWeakUnderAttack] = maxFrame;

	maxFrame = 10;
	Attack* WalkStrongUnderAttack = new Attack(L"image/Ryo/Ryo_Highkick.bmp", 3843, 370, 10, 1, true, RGB(255, 0, 255));
	WalkStrongUnderAttack->Init(14, pos, radius);
	attackMap.insert({ AttackType::WalkStrongUnderAttack, WalkStrongUnderAttack });
	offSetMap.insert({ AttackType::WalkStrongUnderAttack, -70 });
	maxFrameMap[AttackType::WalkStrongUnderAttack] = maxFrame;

}

void Character::Release()
{
	if (animIdle)
	{
		animIdle->Release();
		delete animIdle;
		animIdle = nullptr;
	}

	if (animWalkFront)
	{
		animWalkFront->Release();
		delete animWalkFront;
		animWalkFront = nullptr;
	}

	if (animWalkBack)
	{
		animWalkBack->Release();
		delete animWalkBack;
		animWalkBack = nullptr;
	}

	if (animSitDown)
	{
		animSitDown->Release();
		delete animSitDown;
		animSitDown = nullptr;
	}

	for (auto& iter : attackMap)
	{
		if (nullptr != iter.second) //attackMap의 value 해제
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}

void Character::Update()
{
	++elipseFrame;

	curFrame = elipseFrame / divFrame;

	if (true == isAttacking && maxFrameMap[curAttackType] < curFrame)
	{
		isAttacking = false;
		elipseFrame = curFrame = 0;
		state = CharacterState::Idle;
	}

	if (state == CharacterState::SitDown)
	{
		if (elapsedFrame > 30) // 약 0.5초 동안 앉기 유지
		{
			state = CharacterState::Idle; // 일정 시간이 지나면 다시 Idle 상태로 변경
		}
		else
		{
			elapsedFrame++; // 경과 시간 증가
		}
		return; // 다른 동작 방지
	}

	if (isJumping)
	{
		pos.y += jumpVelocity;  // Y 좌표 변경 (윈API는 Y 증가하면 아래로 이동)
		jumpVelocity += gravity; // 중력 적용 → 하강 속도 점점 증가

		if (jumpFrame < maxJumpFrame - 1)
		{
			jumpFrame++; // 애니메이션 프레임 증가
		}

		if (pos.y >= groundY) // 바닥에 닿았는지 확인
		{
			pos.y = groundY;  // Y 위치를 바닥으로 고정
			isJumping = false; // 점프 종료
			state = CharacterState::Idle; // 착지 후 Idle 상태로 변경
			jumpFrame = 0; // 점프 프레임 초기화
		}
	}
}

void Character::Render(HDC hdc)
{

	if (curAnim)
	{
		switch (state)
		{
		case CharacterState::Idle:
			curAnim->Render(hdc, pos.x, pos.y, curFrame % 10, isFlip);
			break;
		case CharacterState::Attack:
			attackMap[curAttackType]->GetImage()->Render(hdc, pos.x, pos.y + offSetMap[curAttackType], curFrame % maxFrameMap[curAttackType], isFlip);
			break;
		case CharacterState::WalkBack:
			curAnim->Render(hdc, pos.x, pos.y, curFrame % 6, isFlip);
			break;
		case CharacterState::WalkFront:
			curAnim->Render(hdc, pos.x, pos.y, curFrame % 6, isFlip);
			break;
		case CharacterState::SitDown:
			curAnim->Render(hdc, pos.x, pos.y, curFrame % 4, isFlip);
			break;
		case CharacterState::Jump:
			curAnim->Render(hdc, pos.x, pos.y, jumpFrame % maxJumpFrame, isFlip);
			break;
		case CharacterState::Block:
			break;
		case CharacterState::Run:
			break;
		case CharacterState::BackStep:
			break;
		default://None
			break;
		}

	}

}

void Character::Idle()
{
	if (state != CharacterState::Dead && state != CharacterState::Hit && state != CharacterState::Attack)
	{
		if (state == CharacterState::None)
			state = CharacterState::Idle;
	}
}

void Character::WalkFront()
{
	if (state != CharacterState::Dead && state != CharacterState::Hit && state != CharacterState::Attack
		&& state != CharacterState::None)
	{
		if (isFlip)
		{
			pos.x -= moveSpeed;
		}
		else {
			pos.x += moveSpeed;
		}


		this->body->SetRect(GetRectAtCenter(pos.x, pos.y, width, height));
		state = CharacterState::WalkFront;
		curAnim = animWalkFront;

	}
}

void Character::WalkBack()
{
	if (state != CharacterState::Dead && state != CharacterState::Hit && state != CharacterState::Attack)
	{
		if (isFlip)
		{
			pos.x += moveSpeed;
		}
		else {
			pos.x -= moveSpeed;
		}

		this->body->SetRect(GetRectAtCenter(pos.x, pos.y, width, height));
		state = CharacterState::WalkBack;
		curAnim = animWalkBack;

	}

}

void Character::Jump()
{
	if (isJumping) return; // 이미 점프 중이면 실행하지 않음

	isJumping = true;       // 점프 시작
	jumpVelocity = -jumpPower;  // 위로 점프 (윈API에서 Y 감소)
	state = CharacterState::Jump;
	curAnim = animJump;     // 점프 애니메이션 설정
	jumpFrame = 0;          // 점프 프레임 초기화
}

void Character::SitDown()
{
	if (state != CharacterState::Dead && state != CharacterState::Hit && state != CharacterState::SitDown)
	{

		state = CharacterState::SitDown;
		curAnim = animSitDown;
		elapsedFrame = 0;
	}
}

void Character::Dash()
{
	if (state != CharacterState::Dead && state != CharacterState::Hit
		&& state != CharacterState::Attack)
	{
		state = CharacterState::Run;
	}
}

void Character::BackStep()
{
	if (state != CharacterState::Dead && state != CharacterState::Hit
		&& state != CharacterState::Attack)
	{
		state = CharacterState::BackStep;
	}

}

void Character::Block(FPOINT enemypos, Command command)
{
	if (pos.x < enemypos.x)
	{
		if (command == Command::Left)
		{

		}
	}
	else
	{
		if (command == Command::Right)
		{

		}
	}
}

void Character::pAttack(AttackType attacktype)
{
	if (true == isAttacking)
	{
		return;
	}

	curFrame = elipseFrame = 0;
	curAttackType = attacktype;
	isAttacking = true; // 굳이 필요한가 싶지만 일단 써보자.
	state = CharacterState::Attack;
	attackMap[attacktype]->SetPos(pos);
}

void Character::GetDamage(int damage)
{
	//내 체력을 깎고 피격상태로변경, 
	this->hp -= damage;
	GetHit();

}

void Character::GetHit()
{
	//현재상태 -> 피격상태로 변경
	state = CharacterState::Hit;

}

void Character::AddCommand(Command command)
{
	//명령을 받고
	//상태를 보고 명령을 수행할수 있다면 수행
	if (state == CharacterState::SitDown) // 앉아있는 동안 명령을 무시
	{
		return;
	}

	if (command == Command::Up && !isJumping)
	{
		Jump();
		return;
	}

	if (command == Command::A || command == Command::B ||
		command == Command::X || command == Command::Y)
	{
		pAttack(static_cast<AttackType>(command)); // 공격 실행
		return;
	}

	if (isJumping) return; // 점프 중에는 이동 불가 (공격 제외)
	switch (command)
	{
	case Command::Up:
		Jump();
		break;
	case Command::Down:
		SitDown();
		break;
	case Command::Left:
		isFlip ? WalkFront() : WalkBack();	// bFlip이 true란 뜻은? 왼쪽을 보고 있다.
		break;
	case Command::Right:
		isFlip ? WalkBack() : WalkFront();
		break;
	case Command::A: //약한 상단공격
		pAttack(WalkWeakUpperAttack);
		break;
	case Command::B: //강한 상단공격
		pAttack(WalkStrongUpperAttack);
		break;
	case Command::X: //약한 하단공격
		pAttack(WalkWeakUnderAttack);
		break;
	case Command::Y: //강한 하단공격
		pAttack(WalkStrongUnderAttack);
		break;
	default:
		Idle();
	}
}

Character::Character()
{

}

Character::~Character()
{

}

void Character::BodyCollisionDetect(GameObject* owner)
{
	//body 충돌할때 처리
	Character* enemy = dynamic_cast<Character*> (owner);
	if (nullptr != enemy)
	{
		//상대방과 부딪힘
	}
	//공격충돌
	Attack* atk = dynamic_cast<Attack*> (owner);
	if (nullptr != atk)
	{

	}
}