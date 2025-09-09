#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();

	void Update(float dt, class Input& input) override;
};

/*state();
virtual destructor;
void tostate(int id)

onenter(oldstate)0
onexecute0
onexit(newstate)0

protected
int m_state
float m_statetime*/

