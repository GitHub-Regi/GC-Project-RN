#pragma once

#include "Entity.h"

class Enemy : public Entity
{
public: 
	Enemy();

	virtual ~Enemy();

	void Update(float dt) override;

private: 
	int m_Posx;
	int m_Posy;
};

