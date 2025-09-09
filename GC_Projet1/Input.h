#pragma once

enum KeyState {
	neutral,
	keyDown,
	keyUp,
	maintain
};

class Input
{
	private:
		KeyState m_tabKey[256];

	public:
		//Constructeur par défaut
		Input();

		//Destructeur
		virtual ~Input();

		bool IsKey(int key);
		bool IsKeyDown(int key);
		bool IsKeyUp(int key);

		//Getter tabKey
		KeyState getTabKey(int i); 

		//capture l'etat des touches
		void captureInput();
		
		//faire un update
		void update();
};

