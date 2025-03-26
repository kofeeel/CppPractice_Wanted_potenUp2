#pragma once
#include "config.h"
#include "GameObject.h"

class Character;

using namespace std;

class Player : public GameObject
{
private:
	Character* character;

public:
	Player();
	virtual ~Player();

	void Init() override;
	void Release() override;
	void Update() override;
	void Render(HDC hdc) override;

	void AddCommand(Command cmd);
	int GetHP();
	void SelectCharacter(CharacterName name);

	void SetPos(const FPOINT& pos);
};