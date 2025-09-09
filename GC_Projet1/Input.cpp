#include <windows.h>
#include "Input.h"
//#include <winuser.h>

Input::Input()
{
	for (int i = 0; i < 256; i++) {
		m_tabKey[i] = neutral;
	}
	
}

Input::~Input()
{
}

KeyState Input::getTabKey(int i)
{
	return m_tabKey[i];
}

void Input::setTabKey(KeyState tk[256] )
{
	for (int i = 0; i < 256; i++) {
		m_tabKey[i] = tk[i];
	}
}

void Input::captureInput()
{
	for (int i = 0; i < 256; i++) {
		short value = GetAsyncKeyState(i);
		KeyState finalValue;
		if (value < 0) {
			//touche pressé
			finalValue = keyDown;
			if (m_tabKey[i] == keyDown) {
				finalValue = maintain;
			}
		}
		else if (m_tabKey[i] == maintain) {
			finalValue = keyUp;
		}
		else {
			finalValue = neutral;
		}
		m_tabKey[i] = finalValue;
	}
}

void Input::update() {
	captureInput();
}


