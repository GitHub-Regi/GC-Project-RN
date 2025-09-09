#pragma once

#include <Windows.h>

class Timer
{
public:
	Timer();

private:
	DWORD lastTime;

	float m_totalTime;
	float m_deltaTime;

public:

	void Reset();
	void UpdateDeltaTime();
	float getDeltaTime();
};

