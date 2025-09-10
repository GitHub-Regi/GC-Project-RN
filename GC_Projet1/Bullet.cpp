#include "Bullet.h"

/*
Bullet::Bullet(sf::Vector2f position)
{
	shape.setSize(sf::Vector2f(10, 20));
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(position);
	speed = 400.f;

	toState(0);
}
*/

Bullet::Bullet()
{
}

void Bullet::initBullet(sf::Vector2f position)
{
	shape.setSize(sf::Vector2f(20, 40));
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(position);
	speed = 400.f;
}

void Bullet::Update(float dt)
{
	shape.move(sf::Vector2f(0.f, -speed * m_dt));
	
	UpdateStateTime(dt);
	onExecute(m_currentState, dt);

	if (shape.getPosition().y + shape.getSize().y < 100)
	{
		toState(1);
	}
}

void Bullet::onExit(int id)
{
	if (id == 0)
	{
		//Fin du mouvement
	}
	else if (id == 1)
	{
		//Fin de l'explosion
	}
}

void Bullet::onEnter(int id)
{
	if (id == 0)
	{
		//Pret a avancer
	}
	else if (id == 1)
	{
		shape.setFillColor(sf::Color::Red);
	}
	else if (id == 2)
	{
		shape.setFillColor(sf::Color::Transparent);
	}
}

void Bullet::onExecute(int id, float dt)
{
	if (id == 0)
	{
		shape.move(sf::Vector2f(0.f, -speed * dt));
	}
	else if (id == 1)
	{
		if (m_stateTime > 0.5f)
		{
			toState(2);
		}
	}
	else if (id == 2)
	{
		
	}
}
