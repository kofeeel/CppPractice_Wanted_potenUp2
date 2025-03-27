#pragma once
#include "GameObject.h"
#include <vector>

class Missile;
class MissileManager:GameObject
{
private:
	vector<Missile*> missiles;
	vector<Missile*>::iterator iterMissiles;
	//iterator STL 컨테이너 순회를 위한 포인터
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	Missile* AddMissile();
	Missile* GetMissile();
};

