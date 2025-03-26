#include "CollisionManager.h"
#include "CommonFunction.h"


void Collision::SetOwner(GameObject* obj)
{
    this->owner = obj;
}

GameObject* Collision::GetOwner()
{
    return this->owner;
}

CollisionType Collision::GetType()
{
    return this->type;
}

void Collision::SetType(CollisionType type)
{
    this->type = type;
}

void Collision::SetActive(bool bActive)
{
    this->bActive = bActive;
}

bool Collision::GetActive()
{
    return this->bActive;
}

/**/

CollisionRect::CollisionRect()
{
}

const RECT& CollisionRect::GetRect()
{
    // TODO: 여기에 return 문을 삽입합니다.
    return rt;
}

void CollisionRect::SetRect(const RECT& rt)
{
    this->rt = rt;
}


CollisionManager* CollisionManager::GetInstance()
{
    static CollisionManager instance;

    return &instance;
}

CollisionEllipse* CollisionManager::CreateCollisionEllipse(GameObject* obj, int x, int y, int radius)
{
    if (nullptr == obj)
    {
        return nullptr;
    }

    CollisionEllipse* coll = new CollisionEllipse();
    coll->SetActive(true);
    coll->SetOwner(obj);
    coll->SetEllipse(x,y,radius);
    coll->SetType(CollisionType::ELLIPSE);

    collisionMap[obj].push_back(coll);

    return coll;
}

CollisionRect* CollisionManager::CreateCollisionRect(GameObject* obj, const RECT& rt)
{
    if (nullptr == obj)
    {
        return nullptr;
    }

    CollisionRect* coll = new CollisionRect();
    coll->SetActive(true);
    coll->SetOwner(obj);
    coll->SetRect(rt);
    coll->SetType(CollisionType::RECT);

    collisionMap[obj].push_back(coll);
   
    return coll;
}

void CollisionManager::DeleteCollision(Collision* coll)
{
    if (nullptr != coll)
    {
        auto list = collisionMap.at(coll->GetOwner());
        list.remove(coll);   
    }
}

void CollisionManager::Update()
{
    CollisionDetect();
}

void CollisionManager::CollisionDetect()
{
    list<GameObject*> ownerList;

    for (const auto& pair : collisionMap)
    {
        ownerList.push_back(pair.first);
    }

   list<GameObject*>::iterator it = ownerList.begin();
   list<GameObject*>::iterator itBack = ownerList.end();

   if (it == ownerList.end())
   {
        return;
   }
  
   while (it != ownerList.end())
   {

       itBack = ownerList.end();
       itBack--;

       while (it != itBack)
       {
            auto colList1 = collisionMap.at(*it);
            auto colList2 = collisionMap.at(*itBack);

            CollisionDetect(colList1, colList2);
          
            itBack--;
       }

       it++;
   }


}

void CollisionManager::CollisionDetect(list<Collision*>& colList1, list<Collision*>& colList2)
{
    for (auto col1 : colList1)
    {
        for (auto col2 : colList2)
        {
            if (col1->bActive && col2->bActive)
            {
                Detect(col1, col2);
            }
        }
    }
}

void CollisionManager::Detect(Collision* c1, Collision* c2)
{
    if (nullptr != c1 && nullptr != c2)
    {   
        if (c1->GetType() == CollisionType::RECT && c2->GetType() == CollisionType::RECT)
        {
            CollisionRect* rt1 = static_cast<CollisionRect*>(c1);
            CollisionRect* rt2 = static_cast<CollisionRect*>(c2);
            if (RectInRect(rt1->GetRect(), rt2->GetRect()))
            {
                // 충돌.
                c1->detection(c2->GetOwner());
                c2->detection(c1->GetOwner());
            }
        }
        else if (c1->GetType() == CollisionType::ELLIPSE && c2->GetType() == CollisionType::ELLIPSE)
        {
            CEllipse cel1 = ((CollisionEllipse*)c1)->GetEllipse();
            CEllipse cel2 = ((CollisionEllipse*)c1)->GetEllipse();
            if (EllipseInEllipse(cel1, cel2))
            {
                c1->detection(c2->GetOwner());
                c2->detection(c1->GetOwner());
            }
        }
        else 
        {
            CEllipse cel;
            RECT rt;
            if (c1->GetType() == CollisionType::ELLIPSE)
            {
                cel = ((CollisionEllipse*)c1)->GetEllipse();
                rt = ((CollisionRect*)c2)->GetRect();
            }
            else {
                rt = ((CollisionRect*)c1)->GetRect();
                cel = ((CollisionEllipse*)c2)->GetEllipse();
            }

            if (RectInEllipse(rt, cel))
            {
                c1->detection(c2->GetOwner());
                c2->detection(c1->GetOwner());
            }
        }
    }
}

CollisionEllipse::CollisionEllipse()
{
    
}

void CollisionEllipse::SetEllipse(int x, int y, int radius)
{
    this->ellipse.centerX = x;
    this->ellipse.centerY = y;
    this->ellipse.radius = radius;
}

CEllipse CollisionEllipse::GetEllipse()
{
    return this->ellipse;
}
