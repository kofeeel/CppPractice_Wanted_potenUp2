#pragma once
#include "CollisionManager.h"
#include "config.h"
#include "GameObject.h"

class Image;

enum AttackType
{
	WalkWeakUpperAttack,  //
	WalkStrongUpperAttack,//
	WalkWeakUnderAttack,  //
	WalkStrongUnderAttack,//
	SitWeakUpperAttack,   //
	SitStrongUpperAttack, //
	SitWeakUnderAttack,   //
	SitStrongUnderAttack, //
};

class Attack : public GameObject
{
private:
	//데미지
	int damage;
	FPOINT pos; //상대 위치
	int radius;
	bool isFlip;

	//콜리젼 생성하고 사용
	CollisionManager* collisionEllipse;
	Image* image;

public:
	void Init(int damage, FPOINT pos, int radius);
	void BeginAttack();
	void EndAttack(); //공격이 끝났거나 취소시킬때 호출
	void CollisionDetected(GameObject* owner);

	inline void SetPos(FPOINT pos) { this->pos = pos; };
	inline void SetFlip(bool isFlip) { this->isFlip = isFlip; };

	inline Image* GetImage() { return image; };
	Attack();
	Attack(const wchar_t* filePath, int width, int height, int maxFrameX, int maxFrameY, bool isTransparent, COLORREF transColor);
	// (const wchar_t* filePath, int width, int height, int maxFrameX, int maxFrameY, bool isTransparent, COLORREF transColor)
	virtual ~Attack();

};