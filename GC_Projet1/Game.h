#pragma once

#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Bullet.h"

class Game : public State
{
public:
	Game();

	~Game();

private:
	
	Timer m_timer;
	Input* m_input;
	std::vector<Bullet*>* m_bullets;
	Player* m_player;

private: 
	sf::RenderWindow window;
	Timer timer;
	Input input;
	Player player;
	std::vector<Bullet*> bullets;

public: 
	void Run();

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

};

