#include "Missile.h"
#include "CommonFunction.h"

void Missile::Init()
{
	missilePos.x = 0;
	missilePos.y = 0;
	missileSize = 30;
	missileSpeed = 3;	
	rcMissile = GetRectAtCenter(missilePos.x, missilePos.y, missileSize, missileSize);
}

void Missile::Release()
{

}

void Missile::Update()
{
	if(missilePos.y)
 	missilePos.y -= 2 * missileSpeed;
}

void Missile::Render(HDC hdc)
{
	//미사일
	RenderEllipseAtCenter(hdc, missilePos.x, missilePos.y, missileSize, missileSize);
	/*MoveToEx(hdc, missilePos.x, missilePos.y, NULL);*/
}

void Missile::Move()
{
	//barrelsize * sin을 해서 y좌표 구하기

}

void Missile::Dead()
{
}

void Missile::SetPos(int posX, int posY)
{
	pos.x = posX; 
	pos.y = posY; 
}

Missile::Missile()
{
}

Missile::~Missile()
{
}

