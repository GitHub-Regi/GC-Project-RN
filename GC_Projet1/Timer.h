#pragma once
class Timer
{
private:
	unsigned int oldTime = 0;
	unsigned int currentTime = 0;

	float deltaTime = 0.f;
	float totalTime = 0.f;


public:
	void Update();
};

