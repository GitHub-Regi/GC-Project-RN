#pragma once

#include <SFMl/Graphics.hpp>
#include <vector>
#include "State.h"

class Input;
class Bullet;

class Entity : public State
{
protected:
	sf::RectangleShape shape;

	float maxHealth = 100.f;
	float currentHealth;

public:
	Entity();

	virtual ~Entity() = default;

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window)
	{
		window.draw(shape);
	}

	sf::Vector2f GetPos() const { return shape.getPosition(); }
	sf::Vector2f GetSize() const { return shape.getSize(); }
	const sf::RectangleShape& GetShape() const { return shape; }
	float GetCurrentHealth() const { return currentHealth; }
	void SetCurrentHealth(float damage) { currentHealth += damage; }
};

