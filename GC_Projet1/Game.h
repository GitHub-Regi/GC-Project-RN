#pragma once

#include "framework.h"
#include "GC_Projet1.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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

