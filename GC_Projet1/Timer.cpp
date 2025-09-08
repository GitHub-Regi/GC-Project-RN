#include "Timer.h"
#include <Windows.h>
#include <SFML/Graphics.hpp>

void Timer::Update()
{
	oldTime = currentTime;
	currentTime = timeGetTime();
	unsigned int intDeltaTime = currentTime - oldTime;

	deltaTime = intDeltaTime / 1000;
	totalTime += deltaTime;
}
