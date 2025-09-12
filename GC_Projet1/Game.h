#pragma once

#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Bullet.h"
#include "EnemiesManager.h"
#include "Collision.h"
#include "Enemy.h"

class Game : public State
{
public:
	Game();

	~Game();

private:
	EnemiesManager m_enemiesManager;
	sf::RenderWindow window;
	Timer m_timer;
	Input* m_input;
	Player* m_player;
	std::vector<Bullet*>* m_bullets;

	float introTextPositionX = 380.f;
	float introTextPositionY = 310.f;
	float outroTextPositionX = 380.f;
	float outroTextPositionY = 210.f;
	sf::Color textColor = sf::Color::Red;

public: 
	void Run();

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

};

