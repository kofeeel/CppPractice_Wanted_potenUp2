#pragma once
#include "Tank.h"
#include "GameObject.h"
class Missile : public GameObject
{
	// 미사일
	POINT missilePos; //미사일 현재 위치
	RECT rcMissile;    //미사일 충돌체크
	int missileSize; //미사일 사이즈
	float missileSpeed; //미사일 속도
	float missileAngle; //미사일 각도: 탱크한테 받기

public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);
	void Move();
	void Dead();
	
	void SetPos(int posX, int posY);

	Missile();
	~Missile();
};

