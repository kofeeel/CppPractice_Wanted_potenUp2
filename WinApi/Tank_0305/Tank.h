#pragma once
#include "Missile.h"
#include <vector>

using namespace std;

class Tank : public GameObject
{
private:
	vector<Missile*>missiles; 
	POINT pos;
	int size;
	float damage;
	string name;
	RECT rcCollision;

	// 포신
	POINT barrelEnd;
	int barrelSize;
	float barrelAngle;	// 단위 : 도(degree)	0 ~ 180		~	360
						//	    : 라디안(radian)0f ~ 3.14f	~	6.28f

public:
	void Init();	
	void Release();	
	void Update();	
	void Render(HDC hdc);

	void Move();
	void Fire();
	void RotateBarrel(float angle);
	void Dead();

	vector<Missile*>& GetMissiles()
	{
		return missiles;
	}
	Tank();
	~Tank();
};

