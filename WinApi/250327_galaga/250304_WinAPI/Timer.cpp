#include "Timer.h"

void Timer::Init()
{
	isHardware = false;			
	timeScale = 0.0f;			
	timeElapsed = 0.0f;			
	currTime = 0;		
	lastTime = 0;			
	periodFrequency = 0;	
	fpsTimeElapsed = 0.0f;
	fpsFrameCount = 0; 
	FPS = 0;

	isHardware = QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency); //=timeGetTime

	if (isHardware)
	{
		lastTime = QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
		timeScale = 1.0f / periodFrequency; 
	}
	else
	{
		lastTime = timeGetTime();
		timeScale = 0.001f;
	}
}

void Timer::Release()
{

}

void Timer::Tick()
{
	if (isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	}
	else
	{
		currTime = timeGetTime();
		timeScale = 0.001f;
	}

	timeElapsed = (currTime - lastTime) * timeScale;  //일정하게 보정된 시간 deltatime

	fpsTimeElapsed += timeElapsed;
	fpsFrameCount++;

	if (fpsTimeElapsed >= 1.0f)
	{
		FPS = fpsFrameCount;
		fpsFrameCount = 0.0f;
		fpsTimeElapsed = 0.0f;
	}

	lastTime = currTime;
}

float Timer::GetCurrTime()
{
	__int64 time;

	if (isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&time);
	}
	else
	{
		time = timeGetTime();
	}

    return time * timeScale;
}
