#pragma once

#include "Entity.h"

class Bullet : public Entity
{
public :
	Bullet();
	~Bullet();

private:
	float speed = 0.f;

public:
	void initBullet(sf::Vector2f position);

	void Update(float dt) override;

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

	void SetSpeed(float amount) { speed -= amount; }

};

