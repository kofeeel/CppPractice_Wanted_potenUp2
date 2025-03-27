#pragma once
#include "GameObject.h"

class Image;
class Player;
class MissileManager;
class Missile;
class Enemy : public GameObject	// is-a
{
private:
	FPOINT pos;
	float moveSpeed; // 컴퓨터 성능 상관없이 나오도록 하기
	float angle;
	bool isAlive;
	int size;
	//Tank* target;
	Player* target;
	std::unique_ptr<Player*> target2;
	Image* enemyImage;
	int animationFrame;
	int elapsedFrame;
	float elapsedTime; 
	int enemyMaxX;
	bool moveRight;
	MissileManager* missileManager;
	Missile* missile;

public:
	void Init(float posX = 1.0f, float posY = 1.0f);
	void Release();		
	void Update();		
	void Render(HDC hdc);

	void Move();

	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return isAlive;
	}
	inline void SetTarget(Player* target) { this->target = target; }
	inline FPOINT GetPos() { return pos; }
	inline int GetSize() { return size; }

	Enemy();
	~Enemy();

};

