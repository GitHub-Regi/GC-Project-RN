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

private: 
	int m_nbEnemies;

public:
	std::vector<Enemy*> m_enemies;
	std::vector<Bullet*> m_enemyBullets;

	void initEnemies(int nbEnemies, int pattern);

	void updateEnemies(float dt);

	void drawEnemies(sf::RenderWindow& w);

	void AddBullet(Bullet* b);

	void UpdateBullets(float dt);

	void DrawEnemyBullets(sf::RenderWindow& w);

private: 
	int m_nbEnemies;
	int m_spawnLeftX = 25;
	int m_spawnRightX = 1225;
	int m_spawnY = 60;

	enum PatternNames {
		line = 0,
		triangle,
		lineMirror,
		triangleMirror,
		debugPattern
	};

};

