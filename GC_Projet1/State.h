#pragma once
class State
{
	public: 
		State();

		virtual ~State();

	private:
		int m_currentState;
		int m_oldState;
		float m_stateTime;

	public: 
		void toState(int id);

		virtual void onExit(int id) = 0;

		virtual void onEnter(int id) = 0;

		virtual void onExecute(int id) = 0;
};