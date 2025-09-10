#pragma once

#include "Entity.h"
#include "State.h"

class Bullet : public Entity, public State
{
public :
	Bullet(sf::Vector2f position);

private:
	float speed;

public:
	void Update(float dt, class Input& input, std::vector<Bullet*>& bullets) override;

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

};

