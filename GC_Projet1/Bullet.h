#pragma once

#include "Entity.h"

class Bullet : public Entity
{
public :
	//Bullet(sf::Vector2f position);
	Bullet();

private:
	float speed;
	float m_dt;

public:
	void initBullet(sf::Vector2f position);

	void Update(float dt) override;

};

