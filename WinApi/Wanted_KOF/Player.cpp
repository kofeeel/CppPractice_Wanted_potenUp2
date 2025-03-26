#include "Player.h"
#include "Terry.h"
#include "Ryo.h"
#include "Character.h"

Player::Player()
	:character(nullptr)
{
	
}

void Player::Init()
{

}

void Player::Release()
{
	if (nullptr != character)
	{
		delete character;
		character = nullptr;
	}
}

void Player::Update()
{
	character->Update();
}

void Player::Render(HDC hdc)
{
	character->Render(hdc);
}

void Player::AddCommand(Command cmd)
{
	// 여기 다른일을 할진 모르겠네?
	this->character->AddCommand(cmd);
}

int Player::GetHP()
{
	return character->GetHP();
}

void Player::SelectCharacter(CharacterName name)
{
	// BattleManager 클래스에서 Character 객체를 보내주는게 더 괜찮았을듯

	if (nullptr != character)
	{
		character->Release();
		delete character;
		character = nullptr;
	}

	// 	None, Mature, Ryo, Terry, K,
	switch (name)
	{
		case CharacterName::Mature:
		case CharacterName::Ryo:
		case CharacterName::Terry:
		case CharacterName::K:
		default:
			break;
	}

	this->character = new Character();
	this->character->Init();
}

void Player::SetPos(const FPOINT& pos)
{
	this->character->SetPos(pos);
}

Player::~Player()
{
	
}
