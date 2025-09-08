#pragma once

#include <bitset>

class Input
{
	private:
		bool m_keyPress;
		int m_keycode; //basé sur le code ASCII
		std::byte m_tabKey[256]; // keycode/etat


	public:
		//Constructeur par défaut
		Input();

		//Destructeur
		virtual ~Input();



		//Getter keyPress
		bool getKeyPress();

		//Setter keyPress
		void setKeyPress(bool kp);

		//Getter keycode
		int getKeycode();

		//Setter keycode
		void setKeycode(int kc);

		//Getter tabKey
		std::byte getTabKey(int i); 

		//Setter tabKey
		void setTabKey(std::byte tk[256]);



		//capture l'etat des touches
		void captureInput();




};

