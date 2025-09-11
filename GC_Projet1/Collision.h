#pragma once

#include "SFML/Graphics.hpp"
#include "Bullet.h"
#include "Enemy.h"

class Collision 
{

public: 
	Collision();

	virtual ~Collision();

	static bool IsColliding(const sf::RectangleShape& a, const sf::RectangleShape b);
	
};

