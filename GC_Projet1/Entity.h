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
	virtual ~Entity() = default;

	virtual void Update(float dt, Input& input, std::vector<Bullet*>& bullets) = 0;
	virtual void Draw(sf::RenderWindow& window)
	{
		window.draw(shape);
	}

	sf::Vector2f GetPos() const { return shape.getPosition(); }
	sf::Vector2f GetSize() const { return shape.getSize(); }

};

