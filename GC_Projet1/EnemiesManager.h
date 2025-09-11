#pragma once

#include <vector>
#include "Enemy.h"

class EnemiesManager
{
public: 
	EnemiesManager();

	~EnemiesManager();

	void initEnemies(int nbEnemies);

	std::vector<Enemy*> m_enemies;

	void updateEnemies(float dt);

private: 
	int m_nbEnemies;

};

