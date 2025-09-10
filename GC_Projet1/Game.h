#pragma once

#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Bullet.h"

class Game
{
public:
	Game();

	~Game();

private:
	
	Timer m_timer;
	Input* m_input;
	std::vector<Bullet*>* m_bullets;
	Player* m_player;


public: 
	void Run();

};

