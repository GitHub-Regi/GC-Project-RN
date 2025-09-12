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

private: 
	float m_speed;
	int m_pattern;
	int m_goal;

	float m_fireCooldown = 0.f;
	float m_fireRate = 1.f;

	EnemiesManager* enemiesManager;

	enum StateNames {
		spawning = 0,
		alive,
		touched,
	};

	enum PatternNames {
		line = 0, 
		triangle,
		lineMirror,
		triangleMirror,
		debugPattern
	};

	enum Coordinates {
		left = 25,
		right = 1225,
		midX = 640,
		midXForShape = 625,
		top = 60
	};

};

