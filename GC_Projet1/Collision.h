#pragma once

#include "SFML/Graphics.hpp"
#include "Bullet.h"
#include "Enemy.h"

class Collision : Entity
{

public: 
	Collision();

	virtual ~Collision();

	void Update(float dt) override;

private:
	bool IsColliding(const sf::RectangleShape& a, const sf::RectangleShape& b);
	
};

