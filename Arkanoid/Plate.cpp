#include <map>

#include "Plate.h"
#include "InputHandler.h"

void Plate::move() {
	m_position += InputHandler::getInput();
}