#pragma once

#include "Entity.h"

class Bullet : public Entity
{
public :
	Bullet(sf::Vector2f position);

private:
	float speed;

public:
	void Update(float dt, class Input& input, std::vector<Bullet*>& bullets) override;

};

