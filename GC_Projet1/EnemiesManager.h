#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Enemy;
class Bullet;

class EnemiesManager
{
public: 
	EnemiesManager();

	~EnemiesManager();

	void initEnemies(int nbEnemies, int pattern);

	std::vector<Enemy*> m_enemies;
	std::vector<Bullet*> m_enemyBullets;

	void updateEnemies(float dt);

	void drawEnemies(sf::RenderWindow& w);

	void AddBullet(Bullet* b);

	void UpdateBullets(float dt);

	void DrawEnemyBullets(sf::RenderWindow& w);

private: 
	int m_nbEnemies;

};

