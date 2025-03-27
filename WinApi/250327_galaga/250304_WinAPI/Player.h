#pragma once
#include "Image.h"
#include "GameObject.h"

class Missile;
class MissileManager;
class MissileFactory;
class Player: public GameObject
{
private:
	FPOINT pos;
	float moveSpeed;
	float angle;
	bool isAlive;
	int size;
	RECT rcCollision;
	bool isShoot;
	Image* playerImage;
	Image* missileImage;
	KeyManager* key;
	int animationFrame;
	int elapsedFrame;

	//미사일 팩토리로 관리
	/*std::shared_ptr<MissileFactory*> targetMissile;
	std::shared_ptr<MissileFactory*> bombMissile;*/
	Missile* missile;
	MissileManager* missiles;
public:
	void Init();
	void Release();
	void Render(HDC hdc);
	void Update();
	void Move();
	void Shoot();

	inline FPOINT GetPos() { return pos; }
	inline Missile* GetMissiles() { return missile; }

	Player(){}
	~Player(){}
};

