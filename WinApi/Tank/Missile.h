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
	POINT pos;		//�̻����� ���� ��ġ
	float angle;	//�̻����� �̵����� (����)
	int size;		//�̻����� ������
	float fSpeed;	//�̻����� �ӵ�
	bool InScreen;  //�̻����� ȭ��ȿ� �ִ��� Ȯ��
public:
	void Init();
	void Release(); 
	void Update();  //�̻��� ��ġ ���� 
	void Render(HDC hdc); //�̻��� ���� ��ġ �׸���
	bool InScreenCheck(); //�̻����� ȭ��ȿ� ������ true 
	void ReadyToFire(POINT pos, float angle); //������ ������ ��ġ�� �ޱ�
	Missile();
	~Missile();
};

