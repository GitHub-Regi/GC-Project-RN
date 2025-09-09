#pragma once

#include <bitset>

enum KeyState {
	neutral,
	keyDown,
	keyUp,
	maintain
};

class Input
{
	private:
		//std::byte m_tabKey[256]; //tableau detat des touches
		KeyState m_tabKey[256];

	public:
		//Constructeur par défaut
		Input();

		//Destructeur
		virtual ~Input();



		//Getter tabKey
		KeyState getTabKey(int i); 

		//Setter tabKey
		void setTabKey(KeyState tk[256]);



		//capture l'etat des touches
		void captureInput();
		
		//faire un update
		void update();




};

