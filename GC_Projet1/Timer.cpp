#include "Timer.h"

Timer::Timer()
{
	lastTime = timeGetTime();
}

void Timer::UpdateDeltaTime()
{
	DWORD currentTime = timeGetTime();
	DWORD elapsed = currentTime - lastTime;
	lastTime = currentTime;
	m_deltaTime =  elapsed / 1000.f;
}

float Timer::getDeltaTime()
{
	return m_deltaTime;
}
