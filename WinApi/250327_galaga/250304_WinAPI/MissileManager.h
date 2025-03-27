#pragma once
#include "GameObject.h"
#include <vector>

class Missile;
class MissileManager:GameObject
{
private:
	vector<Missile*> missiles;
	vector<Missile*>::iterator iterMissiles;
	//iterator STL �����̳� ��ȸ�� ���� ������
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	Missile* AddMissile();
	Missile* GetMissile();
};

