#include "Timer.h"

Timer::Timer()
{
	QueryPerformanceFrequency(&frequency);
}

void Timer::Start()
{
	QueryPerformanceCounter(&startTime);
}

void Timer::Stop()
{
	QueryPerformanceCounter(&endTime);
}

double Timer::GetElapsedTime() const
{
	return static_cast<int>(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart;
}
