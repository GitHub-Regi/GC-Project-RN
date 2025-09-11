#pragma once

#include "Entity.h"

class Enemy : public Entity
{
public: 
	Enemy();

	virtual ~Enemy();

	void initEnemy();

	void Update(float dt) override;

	void onExit(int id) override;

	void onEnter(int id) override;

	void onExecute(int id, float dt) override;

private: 
	int m_Posx;
	int m_Posy;
	float m_speed;
};

