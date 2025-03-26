/*
	�ǽ�1. �̻��� �ѹ� ���
	�ǽ�2. �̻��� ������ ���
	�ǽ�3. ��ų��1 (360�� �̻���) ���
	�ǽ�4. ��ų��2 (��ü ��ȹ) ���
*/

#pragma once
#include "GameObject.h"

class Missile : public GameObject
{
	POINT pos;		//�̻����� ������ġ
	float angle;	//�̻����� �̵����� 
	int size;		//�̻����� ������
	float fSpeed;	//�̻����� �ӵ�
	bool isActive;  //ȭ��ȿ� �ִ��� Ȯ��
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

