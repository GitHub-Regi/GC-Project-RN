#pragma once

#include <Windows.h>

class Timer
{
public:
	Timer();

private:
	DWORD lastTime;

public:
	void Reset();
	float GetDeltaTime();
};

