#pragma once
class State
{
	public: 
		State();

		virtual ~State();

	protected:
		int m_currentState;
		int m_oldState;
		float m_stateTime;

	public: 
		void toState(int id);

		void UpdateStateTime(float dt) { m_stateTime += dt; }

		int GetState() const { return m_currentState; }

		virtual void onExit(int id) = 0;

		virtual void onEnter(int id) = 0;

		virtual void onExecute(int id, float dt) = 0;
};