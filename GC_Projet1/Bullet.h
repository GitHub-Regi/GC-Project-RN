#pragma once

#include "Entity.h"
#include "State.h"

class Bullet : public Entity, public State
{
public :
	Bullet();
	~Bullet();

private:
	float speed = 400.f;

public:
	void initBullet(sf::Vector2f position);

	void Update(float dt) override;

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

};

