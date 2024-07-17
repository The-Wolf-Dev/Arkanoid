#include "InputHandler.h"

Vector2Di InputHandler::handleKeyInput(const int code) {
	Vector2Di vec2di = Vector2Di::ZERO;
	switch (code)
	{
	case KEY_LEFT:
		vec2di = Vector2Di::LEFT;
		break;
	case KEY_RIGHT:
		vec2di = Vector2Di::RIGHT;
		break;
	default:
		break;
	}

	return vec2di;
}

Vector2Di InputHandler::getInput() {
	int pressed_key = KEY_UNDEFINED;
	if (_kbhit()) {
		pressed_key = _getch();
	}
	return handleKeyInput(pressed_key);
}