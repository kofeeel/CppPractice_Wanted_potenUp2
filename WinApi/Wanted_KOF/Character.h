#pragma once
#include "config.h"
#include "GameObject.h"
#include "Attack.h"
#include <map>
#include <queue>
#include <list>
#include <string>

using namespace std;

class Attack;
class CollisionRect;
class Image;

enum class CharacterState
{
	Idle,   //플레이어가 멈춰있는 상태
	WalkFront,   //플레이어가 앞으로 걷고있는 상태
	WalkBack,	// 플레이어가 뒤로 걷는다.
	SitDown,//플레이어가 앉아있는 상태
	Attack, //플레이어가 공격당한 상태
	Hit,    //플레이어가 피격당한 상태
	Block,  //플레이어가 공격방어 상태
	Run,    //플레이어가 뛰고있는 상태
	Dead,   //플레이어가 죽은	  상태
	Jump,  //플레이어가  점프하는 상태
	BackStep, //플레이어가 백스텝중인 상태
	None    //플레이어가 아무것도하지않는 상태
};

class Character : public GameObject
{
protected:
	FPOINT pos;				//캐릭터 위치
	int width;
	int height;
	int hp;					//캐릭터 체력
	float moveSpeed;		//캐릭터 이동속도

	float jumpVelocity = 0.0f; // 점프 속도 (상승 및 하강)
	float gravity = 0.5f;      // 중력 값
	float jumpPower = 10.0f;   // 점프 초기 속도
	float groundY = 0.0f;      // 캐릭터가 설 수 있는 바닥 Y 좌표
	int jumpFrame = 0;         // 점프 애니메이션 프레임 (최대 16프레임)
	const int maxJumpFrame = 16; // 점프 애니메이션 최대 프레임

	CharacterName name;		//캐릭터 이름
	CharacterState state;	//캐릭터 상태

	map<AttackType, Attack*> attackMap;//캐릭터 어택 타입
	map<AttackType, int> offSetMap;//캐릭터 어택 타입
	list<Command>			CommandList;

	map<AttackType, int> maxFrameMap;//캐릭터 어택 타입
	int curFrame;
	int divFrame;
	int elipseFrame;
	
	bool isAttacking;
	bool isFlip;
	bool isJumping = false;    // 점프 상태 여부
	
	AttackType	curAttackType;

	//충돌처리
	CollisionRect* body;
	//애니메이션 관리
	Image* animIdle;
	Image* animWalkBack;
	Image* animWalkFront;
	Image* animSitDown;
	Image* animJump;

	Image* curAnim; // 현재 상태에 따른 실행할 애니메이션.


	int currFrame;
	int elapsedFrame;


public:
	//이동
	virtual void Idle();					 //정지 상태
	virtual void WalkFront();				 //왼쪽으로 이동
	virtual void WalkBack();			     //오른쪽으로 이동
	virtual void Jump();					 //점프
	virtual void SitDown();					 //앉기
	virtual void Dash();					 //대쉬 
	virtual void BackStep();				 //백스탭 
	//방어를 몇초동안 유지할건지
	virtual void Block(FPOINT enemypos, Command command);//방어

	//공격 
	virtual void pAttack(AttackType attacktype); //기본공격
	//virtual void chooseAttack(CharacterState state); //현재상태,입력받아서 공격결정
	//피격 
	virtual void GetDamage(int damage); //피격 데미지 입음
	virtual void GetHit(); //피격 당해서 밀려남

	virtual void AddCommand(Command command);

	void SetPos(FPOINT pos);
	inline void SetFlip(bool isFlip) { this->isFlip = isFlip; };

	void BodyCollisionDetect(GameObject* owner);

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

public:
	inline int GetHP() { return hp; };
	void SetHP(int hp) { this->hp = hp; };

	Character();
	virtual ~Character();

};