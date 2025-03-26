/*
	실습1. 미사일 한발 쏘기
	실습2. 미사일 여러발 쏘기
	실습3. 스킬샷1 (360도 미사일) 쏘기
	실습4. 스킬샷2 (자체 기획) 쏘기
*/

#pragma once
#include "GameObject.h"

class Missile : public GameObject
{
	POINT pos;		//미사일의 현재위치
	float angle;	//미사일의 이동방향 
	int size;		//미사일의 사이즈
	float fSpeed;	//미사일의 속도
	bool isActive;  //화면안에 있는지 확인
public:
	void Init(POINT startPos, float direction);
	void Release();
	void Update();
	void Render(HDC hdc);
	bool IsDisappear();
	bool GetActive();
	Missile();
	~Missile();
};

