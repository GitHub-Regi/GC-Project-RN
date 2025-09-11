#pragma once

#include <vector>
#include "Entity.h"
#include "Input.h"
#include "Bullet.h"
#include "State.h"


class Player : public Entity
{
public:
	Player();

	Player(Input* input, std::vector<Bullet*>* bullets);

	~Player();

	void initPlayer();

	void Update(float dt) override;

private:
	Input* m_input;
	std::vector<Bullet*>* m_bullets;

	float speed = 0.f;

public:

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;
};


