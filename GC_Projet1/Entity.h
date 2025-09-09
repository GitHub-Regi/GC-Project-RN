#pragma once

#include <SFMl/graphics.hpp>
#include "Input.h"
#include "State.h"

class Entity : public State
{
protected:
	sf::RectangleShape shape;

public:
	virtual ~Entity() = default;

	virtual void Update(float dt, Input& input) = 0;
	virtual void Draw(sf::RenderWindow& window)
	{
		window.draw(shape);
	}

};

