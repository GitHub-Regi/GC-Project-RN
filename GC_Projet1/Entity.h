#pragma once

#include <SFMl/Graphics.hpp>
#include <vector>

class Input;
class Bullet;

class Entity 
{
protected:
	sf::RectangleShape shape;

public:
	Entity();

	virtual ~Entity() = default;

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window)
	{
		window.draw(shape);
	}

};

