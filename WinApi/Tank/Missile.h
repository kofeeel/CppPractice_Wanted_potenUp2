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
	POINT pos;		//미사일의 현재 위치
	float angle;	//미사일의 이동방향 (각도)
	int size;		//미사일의 사이즈
	float fSpeed;	//미사일의 속도
	bool InScreen;  //미사일이 화면안에 있는지 확인
public:
	void Init();
	void Release(); 
	void Update();  //미사일 위치 변경 
	void Render(HDC hdc); //미사일 현재 위치 그리기
	bool InScreenCheck(); //미사일이 화면안에 있으면 true 
	void ReadyToFire(POINT pos, float angle); //포신의 각도와 위치를 받기
	Missile();
	~Missile();
};

