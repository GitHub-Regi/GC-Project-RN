#pragma once

#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Bullet.h"
#include "EnemiesManager.h"

class Game : public State
{
public:
	Game();

	~Game();

private:
	sf::RenderWindow window;
	Timer m_timer;
	EnemiesManager m_enemiesManager;
	Input* m_input;
	std::vector<Bullet*>* m_bullets;
	Player* m_player;

public: 
	void Run();

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

};

