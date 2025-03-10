#pragma once
#include "Missile.h"
#include <vector>

using namespace std;

class Tank : public GameObject
{
private:
	POINT pos;
	int size;
	float damage;
	string name;
	RECT rcCollision;

	// ����
	POINT barrelEnd;
	int barrelSize;
	float barrelAngle;	// ���� : ��(degree)	0 ~ 180		~	360
						//	    : ����(radian)0f ~ 3.14f	~	6.28f
	Missile* missile;
	vector<Missile*> missiles; //������ �̻����� ��� �迭
public:
	void Init();	
	void Release();	
	void Update();	
	void Render(HDC hdc);
	void Move();
	void Fire();
	void Burst(); //���� 3�߽�
	void RotateBarrel(float angle);
	void Dead();
	Tank();
	~Tank();
};

