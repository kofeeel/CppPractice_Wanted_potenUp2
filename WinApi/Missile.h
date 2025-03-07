#pragma once
#include "Tank.h"
#include "GameObject.h"
class Missile : public GameObject
{
	// �̻���
	POINT missilePos; //�̻��� ���� ��ġ
	RECT rcMissile;    //�̻��� �浹üũ
	int missileSize; //�̻��� ������
	float missileSpeed; //�̻��� �ӵ�
	float missileAngle; //�̻��� ����: ��ũ���� �ޱ�

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

