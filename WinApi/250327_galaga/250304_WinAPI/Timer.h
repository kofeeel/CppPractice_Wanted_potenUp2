#pragma once
#include "config.h"

class Timer
{
private:
	bool isHardware;			//고성능 타이머를 사용할 수 있는지 체크
	float timeScale;			//경과 진동수를 초당 진동수로 나눠서 
								//진동수를 시간으로 환산
	float timeElapsed;			//마지막 시간과 현재시간의 경과량을 저장
	__int64 currTime;			//현재	시간
	__int64 lastTime;			//이전	시간
	__int64 periodFrequency;	//고성능 타이머의 주파수 (초당 진동수)

	float fpsTimeElapsed;		//프레임 경과 시간(1초를 확인할때 사용)
	unsigned long fpsFrameCount; // 초당 프레임 수 
	unsigned long FPS;

public:

	void Init();
	void Release();
	void Tick();
	float GetCurrTime();

	inline unsigned long  GetFPS() { return FPS; }
	inline float GetDeltaTime() { return timeElapsed; }
};

