#pragma once

#include "Entity.h"

class Bullet : public Entity
{
public :
	Bullet(sf::Vector2f position);

private:
	float speed = 0.f;

public:
	void Update(float dt, class Input& input) override;

};

