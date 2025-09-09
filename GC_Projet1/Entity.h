#pragma once

#include <SFMl/graphics.hpp>
#include <vector>
#include "Input.h"
#include "Bullet.h"


class Entity
{
protected:
	sf::RectangleShape shape;

public:
	virtual ~Entity() = default;

	virtual void Update(float dt, Input& input, std::vector<Bullet*>& bullets) = 0;
	virtual void Draw(sf::RenderWindow& window)
	{
		window.draw(shape);
	}

};

