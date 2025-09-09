#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position)
{
	shape.setSize(sf::Vector2f(20, 40));
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(position);
	speed = 400.f;
}

void Bullet::Update(float dt, class Input& input, std::vector<Bullet*>& bullets)
{
	shape.move(sf::Vector2f(0.f, speed * dt));
	
}
