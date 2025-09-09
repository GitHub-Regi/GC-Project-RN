#include "Input.h"
#include <winuser.h>

bool Input::IsKeyPressed(int vKey)
{
	return (GetAsyncKeyState(vKey) & 0x8000) != 0;
}


