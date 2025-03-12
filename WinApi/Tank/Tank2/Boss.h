#pragma once
#include "GameObject.h"
class Tank;
class Boss : public GameObject
{
	FPOINT position; 
	Tank* target;
	float hp;
	int size;
	float speed;
	float damage;
	RECT rcCollision;

public:
	void Init(Tank* tank);
	void Release();
	void Update();
	void Render(HDC hdc);
	void Move();
	bool IsDead() { return hp <= 0; }
	FPOINT GetPos() { return position; }
	int GetSize() { return size; }
	float GetDamage() { return damage; }
	void AttackedByBullet(int damage) { hp -= damage; }
	void AttackedByTank() { hp = 0; }

};

