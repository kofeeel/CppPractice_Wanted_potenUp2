#pragma once
#include "config.h"

class Timer
{
private:
    LARGE_INTEGER frequency; // �ʴ� ī������ ����
    LARGE_INTEGER startTime; // ���� �ð�
    LARGE_INTEGER endTime;   // ���� �ð�

public:
    Timer();

    void Start();
    void Stop();
    double GetElapsedTime() const;
};

