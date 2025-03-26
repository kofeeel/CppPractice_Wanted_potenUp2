#pragma once
#include "config.h"
#include "GameObject.h"
#include <list>
#include <map>
#include <functional>

enum class CollisionType
{
	RECT, ELLIPSE
};

class Collision : public GameObject
{

private:
	GameObject* owner;
	bool bActive;
	std::function<void(GameObject*)> detection;
	CollisionType type;
public:
	void Bind(std::function<void(GameObject*)> func) {
		detection = func;
	}

	void SetActive(bool bActive);
	bool GetActive();

	void SetOwner(GameObject* obj);
	GameObject* GetOwner();

	CollisionType GetType();
	void SetType(CollisionType type);

	friend class CollisionManager;
};

class CollisionRect : public Collision
{
private:
	RECT rt;
		
public:
	CollisionRect();

	const RECT& GetRect();
	void SetRect(const RECT& rt);

};

class CollisionEllipse : public Collision
{
private:
	CEllipse ellipse;

public:
	CollisionEllipse();
	void SetEllipse(int x, int y, int radius);
	CEllipse GetEllipse();
};

// CollisionManager
class CollisionManager : public GameObject
{
	private:
		map<GameObject*, list<Collision*>> collisionMap;
		
	public:
		static CollisionManager* GetInstance();
		CollisionEllipse* CreateCollisionEllipse(GameObject* owner, int x, int y, int radius);
		CollisionRect* CreateCollisionRect(GameObject* owner, const RECT& rt);

		void DeleteCollision(Collision* coll);

		void Update() override;
		void CollisionDetect();
		void CollisionDetect(list<Collision*>& colList1, list<Collision*>& colList2);
		void Detect(Collision* c1, Collision* c2);

		CollisionManager& operator =(CollisionManager&) = delete;
};

