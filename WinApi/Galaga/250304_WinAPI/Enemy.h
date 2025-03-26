#pragma once
#include "GameObject.h"

class Tank;
class Image;
class Enemy : public GameObject	// is-a
{
private:
	FPOINT pos;
	float moveSpeed;
	float angle;
	bool isAlive;
	int size;
	Tank* target;
	Image* image;
	int animationFrame;
	int elapsedFrame;

public:
	void Init(float posX = 0.0f, float posY = 0.0f);		
	void Release();		
	void Update();		
	void Render(HDC hdc);

	void Move();

	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return isAlive;
	}
	inline void SetTarget(Tank* target) { this->target = target; }
	inline FPOINT GetPos() { return pos; }
	inline int GetSize() { return size; }

	Enemy();
	~Enemy();

};

