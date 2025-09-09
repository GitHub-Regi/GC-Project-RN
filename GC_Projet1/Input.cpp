#include <Windows.h>
#include "Input.h"

/*Input::Input()
{
	m_keyPress = false;
	m_keycode = 0;
	for (int i = 0; i < 256; i++) {
		m_tabKey[i] = std::byte{0};
	}
	
}

bool Input::getKeyPress()
{
	return m_keyPress;
}

void Input::setKeyPress(bool kp)
{
	m_keyPress = kp;
}

int Input::getKeycode()
{
	return m_keycode;
}

void Input::setKeycode(int kc)
{
	m_keycode = kc;
}

std::byte Input::getTabKey(int i)
{
	return m_tabKey[i];
}

void Input::setTabKey(std::byte tk[256] )
{
	for (int i = 0; i < 256; i++) {
		m_tabKey[i] = tk[i];
	}
}

void Input::captureInput()
{
	for (int i = 0; i < 256; i++) {
		short value = GetAsyncKeyState(i);
		//traduire value en un etat de la touche -> 0,1,2 ou 3 -> finalValue
		int finalValue;
		m_tabKey[i] = std::byte{finalValue}; //final value = 0,1,2 ou 3 pour l'enum
	}
}*/


