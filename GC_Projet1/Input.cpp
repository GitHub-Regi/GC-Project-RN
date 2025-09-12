#include <windows.h>
#include "Input.h"

Input::Input()
{
	for (int i = 0; i < 256; i++) {
		m_tabKey[i] = neutral;
	}
}

Input::~Input()
{
}

bool Input::IsKey(int key)
{
	if (m_tabKey[key] == maintain || m_tabKey[key] == keyDown) {
		return true;
	}
	return false;
}

bool Input::IsKeyDown(int key)
{
	if (m_tabKey[key] == keyDown) {
		return true;
	}
	return false;
}

bool Input::IsKeyUp(int key)
{
	if (m_tabKey[key] == keyUp) {
		return true;
	}
	return false;
}

KeyState Input::getTabKey(int i)
{
	return m_tabKey[i];
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
			if (m_tabKey[i] == maintain) {
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


