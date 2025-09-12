#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::initBullet(sf::Vector2f position)
{
	shape.setSize(sf::Vector2f(10, 20));
	shape.setFillColor(sf::Color::Blue);
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
}

void Bullet::onExecute(int id, float dt)
{
	if (id == 0)
	{
		shape.move(sf::Vector2f(0.f, -speed * dt));

		/*if (shape.getPosition().y + shape.getSize().y < 100)
		{
			toState(1);
		}*/
	}
	else if (id == 1)
	{
		if (m_stateTime >= 0.05f)
		{
			toState(2);
		}
	}
	else if (id == 2)
	{
		//destruction dans game
	}
}
