#pragma once

#include <vector>
#include "Entity.h"
#include "Input.h"
#include "Bullet.h"


class Player : public Entity
{
public:
	Player();

	void Update(float dt, class Input& input, std::vector<Bullet*>& bullets) override;
};


