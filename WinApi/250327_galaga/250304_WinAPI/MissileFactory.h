#pragma once
#include "Missile.h"
#include "MissileManager.h"

class MissileFactory
{
public: 
	virtual void TagetMissileInit() = 0;
	virtual void BombMissileInit() = 0;
private:
};

class TargetMissileFactory : public MissileFactory
{
private:
	int size;
	FPOINT pos;
public:
	//적위치를 따라가는 미사일 생성
	void TargetMissileInit()
	{
		//targetMissile
	}
};

class BombMissileFactory : public MissileFactory
{
private:

public:
};