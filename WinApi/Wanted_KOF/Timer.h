#pragma once
#include "config.h"

class Timer
{
private:
    LARGE_INTEGER frequency; // 초당 카운터의 단위
    LARGE_INTEGER startTime; // 시작 시간
    LARGE_INTEGER endTime;   // 종료 시간

public:
    Timer();

    void Start();
    void Stop();
    double GetElapsedTime() const;
};

