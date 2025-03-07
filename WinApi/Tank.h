#pragma once
#include "GameObject.h"
class Missile;

class Tank : public GameObject
{
protected:
	POINT pos;
	int size;
	float damage;
	string name;
	RECT rcCollision;
	bool isFire;

	// ����
	POINT barrelEnd;
	int barrelSize;
	float barrelAngle;	//S ���� : ��(degree)	0 ~ 180		~	360
						//	    : ����(radian)0f ~ 3.14f	~	6.28f

	//�̻���
	Missile* missiles[5];
public:
	void Init();	
	void Release();	
	void Update();	
	void Render(HDC hdc);
	void Move();
	void Fire();
	void RotateBarrel(float angle);
	void Dead();
	POINT GetBarrelPos();
	Tank();
	~Tank();
};