#include "State.h"

State::State()
	: m_currentState(0), m_oldState(-1), m_stateTime(0.f)
{

}

State::~State()
{

}

void State::toState(int id)
{
	if (id != m_currentState)
	{
		onExit(m_currentState);
		m_oldState = m_currentState;
		m_currentState = id;
		m_stateTime = 0.f;
		onEnter(id);
	}
}
