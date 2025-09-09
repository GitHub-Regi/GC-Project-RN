#include "State.h"

void State::toState(int id)
{
	onExit(id);
	m_oldState = m_currentState;
	onEnter(id);
	m_currentState = id;
}
