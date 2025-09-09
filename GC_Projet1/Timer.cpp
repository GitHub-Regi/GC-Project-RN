#include "Timer.h"

Timer::Timer()
{
	lastTime = timeGetTime();
}

void Timer::Reset()
{
	lastTime = timeGetTime();
}

float Timer::GetDeltaTime()
{
	DWORD currentTime = timeGetTime();
	DWORD elapsed = currentTime - lastTime;
	lastTime = currentTime;
	return elapsed / 1000.f;
}
