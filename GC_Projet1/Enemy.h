#pragma once

#include "Entity.h"
#include "Collision.h"
#include "EnemiesManager.h"

class Enemy : public Entity
{
public: 
	Enemy();

	virtual ~Enemy();

private: 
	EnemiesManager* enemiesManager;

	float m_speed;

	int m_pattern;

	sf::Vector2f m_goal;

	float enemySizeX = 30.f;
	float enemySizeY = 50.f;
	float enemyOriginX = 0.f;
	float enemyOriginY = 0.f;

	float m_fireCooldown = 0.f;
	float m_fireRate = 1.5f;

	sf::Color enemyColor = sf::Color(255, 140, 0, 255);
	sf::Color enemyBulletsColor = sf::Color(192, 192, 192, 255);

public:
	void initEnemy(int spawnX, int spawnY, int pattern, EnemiesManager* enemiesManager);

	void Update(float dt) override;

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;
};

