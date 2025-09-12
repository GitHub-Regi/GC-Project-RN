#pragma once

#include <vector>
#include "Entity.h"
#include "Input.h"
#include "Bullet.h"

class Player : public Entity
{
public:
	Player();

	Player(Input* input, std::vector<Bullet*>* bullets);

	~Player();

private:
	Input* m_input;
	std::vector<Bullet*>* m_bullets;

	float playerSizeX = 40.f;
	float playerSizeY = 70.f;
	float playerOriginX = 0.f;
	float playerOriginY = 0.f;
	float playerPositionX = 620.f;
	float playerPositionY = 600.f;
	float speed = 350.f;

	sf::Color playerColor = sf::Color(34, 139, 34, 255);
	sf::Color playerColorImpact = sf::Color(255, 215, 0, 255);
	sf::Color playerColorCrash = sf::Color::Red;
	sf::Color playerBulletsColor = sf::Color(30, 144, 255, 255);

	int spaceBar = 32;

	enum StateNames {
		alive = 0,
		touched,
		dead
	};

public:
	void initPlayer();

	void Update(float dt) override;

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;
};


