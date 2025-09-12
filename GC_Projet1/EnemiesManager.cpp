#include "EnemiesManager.h"

EnemiesManager::EnemiesManager() : m_nbEnemies()
{
}

EnemiesManager::~EnemiesManager()
{
	//detruire tout les enemies dans le vector
	for (int i = m_enemies.size() -1 ; i >= 0; i--) {
		delete m_enemies[i];
		m_enemies.pop_back();
		m_nbEnemies--;
	}
}

void EnemiesManager::initEnemies(int nbEnemies, int pattern)
{
	m_nbEnemies = nbEnemies;
	for (int i = 0; i < m_nbEnemies * 60; i = i + 60) {
		Enemy* e = new Enemy;
		if (pattern == 0 || pattern == 1 || pattern == 4){
			e->initEnemy(25, 60 - i, pattern);
		}
		else if (pattern == 2 || pattern == 3) {
			e->initEnemy(1225, 60 - i, pattern);
		}
		m_enemies.push_back(e);
	}
}

void EnemiesManager::updateEnemies(float dt)
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i]->Update(dt);
	}
}

void EnemiesManager::drawEnemies(sf::RenderWindow& w)
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i]->Draw(w);
	}
}
