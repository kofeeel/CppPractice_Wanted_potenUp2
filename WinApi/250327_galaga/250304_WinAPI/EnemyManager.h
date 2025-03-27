#pragma once
#include "GameObject.h"
#include "MissileManager.h"
#include "Missile.h"
#include <vector>

class Enemy;
class EnemyManager: public GameObject
{
private:
	vector<Enemy*> vEnemies;
	MissileManager* enemyMissiles;
	float shootTimer;
	float shootInterval;
	wchar_t szText[128];

public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void Move();
	void AddEnemy(int size);
	void Shoot();
};

