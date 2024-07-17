#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <conio.h>

#include "Vector2Di.h"

enum Keys {
	KEY_UNDEFINED,
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	KEY_ENTER = 13,
	KEY_ESC = 27
};

class InputHandler
{
	static Vector2Di handleKeyInput(const int code);
public:
	static Vector2Di getInput();
};

#endif // INPUTHANDLER_H

