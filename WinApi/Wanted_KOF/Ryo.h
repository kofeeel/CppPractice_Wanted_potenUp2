#pragma once
#include "Character.h"
class Ryo : public Character
{
public:
	//�̵�
	virtual void Idle() override;					 //���� ����
	virtual void WalkBack() override;				 //�������� �̵�
	virtual void WalkFront() override;			     //���������� �̵�
	virtual void SitDown() override;					 //�ɱ�
	virtual void Dash() override;					 //�뽬 
	virtual void BackStep() override;				 //�齺�� 
	//�� ���ʵ��� �����Ұ���
	// 
	//���� 
	virtual void pAttack(AttackType attacktype) override; //����Ÿ�� �Է¹޾Ƽ� �⺻����
	//�ǰ� 
	virtual void GetDamage(int damage) override; //�ǰ� ������ ����
	virtual void GetHit() override; //�ǰ� ���ؼ� �з���
	virtual void AddCommand(Command command) override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	Ryo();
	virtual ~Ryo();
};

