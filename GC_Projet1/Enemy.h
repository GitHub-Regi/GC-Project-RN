#pragma once

#include "Entity.h"
#include "Collision.h"
#include "EnemiesManager.h"

class Enemy : public Entity
{
public: 
	Enemy();

	virtual ~Enemy();

	void initEnemy(int spawnX, int spawnY, int pattern, EnemiesManager* enemiesManager);

	void Update(float dt) override;

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

private: 
	float m_speed;
	int m_pattern;
	sf::Vector2f m_goal;
	//std::vector<Bullet*>* m_bullets;

	float m_fireCooldown = 0.f;
	float m_fireRate = 1.5f;

	EnemiesManager* enemiesManager;
};

