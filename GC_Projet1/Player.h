#pragma once

#include <vector>
#include "Entity.h"
#include "Input.h"
#include "Bullet.h"
//#include "State.h"


class Player : public Entity//, public State
{
public:
	Player();

	~Player();

private:
	//float speed = 0.f;

public:
	void Update(float dt, class Input& input, std::vector<Bullet*>& bullets) override;

	//virtual void onExit(int id) = 0;

	//virtual void onEnter(int id) = 0;

	//virtual void onExecute(int id, float dt) = 0;
};


