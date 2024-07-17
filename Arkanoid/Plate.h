#ifndef PLATE_H
#define PLATE_H

#include "Vector2Di.h"

class Plate
{
	Vector2Di m_position;
	int m_width = 2;
	char m_symbol = '-';

public:
	Plate(const Vector2Di& position) : m_position{ position } {};

	void setPosition(const Vector2Di& position) { m_position = position; };
	Vector2Di getPosition() const { return m_position; };
	int getWidth() const { return m_width; };
	char getSymbol() const { return m_symbol; };
	void move();
};

#endif // PLATE_H