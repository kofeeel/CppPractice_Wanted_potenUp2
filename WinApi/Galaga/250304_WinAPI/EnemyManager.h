#pragma once
#include "GameObject.h"
#include <vector>

// 1. WinSizeX, Y를 사막배경에 맞춰서 변경
// 2. 백그라운드를 사막으로 변경
// 3. 플레이어 rocket bmp 구현
// 4. 적 10마리 움직임 구현
// 5. 미사일 매니저 구현 - 플레이어도 사용, 적 사용
// 6. 적이 1마리씩 밑으로 돌격한다.(중간에 미사일 1발 발사)

class Enemy;
class EnemyManager : public GameObject
{
private: 
	Enemy* enemys;
	vector<Enemy*> vecEnemys;
	wchar_t szText[128];

public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
};

