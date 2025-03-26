#pragma once
#include "Character.h"
class Ryo : public Character
{
public:
	//이동
	virtual void Idle() override;					 //정지 상태
	virtual void WalkBack() override;				 //왼쪽으로 이동
	virtual void WalkFront() override;			     //오른쪽으로 이동
	virtual void SitDown() override;					 //앉기
	virtual void Dash() override;					 //대쉬 
	virtual void BackStep() override;				 //백스탭 
	//방어를 몇초동안 유지할건지
	// 
	//공격 
	virtual void pAttack(AttackType attacktype) override; //공격타입 입력받아서 기본공격
	//피격 
	virtual void GetDamage(int damage) override; //피격 데미지 입음
	virtual void GetHit() override; //피격 당해서 밀려남
	virtual void AddCommand(Command command) override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	Ryo();
	virtual ~Ryo();
};

