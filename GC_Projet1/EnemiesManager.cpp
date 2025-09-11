#include "EnemiesManager.h"

EnemiesManager::EnemiesManager() : m_nbEnemies()
{
}

EnemiesManager::~EnemiesManager()
{
	//detruire tout les enemies dans le vector
	for (int i = m_nbEnemies ; i > 0; i--) {
		delete m_enemies[i];
		m_enemies.pop_back();
		m_nbEnemies--;
	}
}

void EnemiesManager::initEnemies(int nbEnemies)
{
	m_nbEnemies = nbEnemies;
	for (int i = 0; i < m_nbEnemies; i++) {
		Enemy* e = new Enemy;
		m_enemies.push_back(e);
	}
}

void EnemiesManager::updateEnemies(float dt)
{
	for (int i = 0; i < m_nbEnemies; i++) {
		m_enemies[i]->Update(dt);
	}
}
