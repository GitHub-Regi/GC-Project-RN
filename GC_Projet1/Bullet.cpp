#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::initBullet(sf::Vector2f position, sf::Color color)
{
	shape.setSize(sf::Vector2f(10, 20));
	shape.setFillColor(color);
	shape.setPosition(position);
	
	toState(0);
}

void Bullet::Update(float dt)
{	
	UpdateStateTime(dt);
	onExecute(m_currentState, dt);
}

void Bullet::onExit(int id)
{
}

void Bullet::onEnter(int id)
{
	if (id == 1)
	{
		shape.setFillColor(sf::Color::Red);
	}
}

void Bullet::onExecute(int id, float dt)
{
	if (id == moving)
	{
		shape.move(sf::Vector2f(0.f, speed * dt));
	}
	else if (id == explodes)
	{
		if (m_stateTime >= 0.05f)
		{
			toState(2);
		}
	}
}
