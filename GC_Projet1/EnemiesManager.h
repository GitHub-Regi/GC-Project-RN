#pragma once

#include <vector>
#include "Enemy.h"

class EnemiesManager
{
public: 
	EnemiesManager();

	~EnemiesManager();

	void initEnemies(int nbEnemies, int pattern);

	std::vector<Enemy*> m_enemies;

	void updateEnemies(float dt);

	void drawEnemies(sf::RenderWindow& w);

private: 
	int m_nbEnemies;

};

