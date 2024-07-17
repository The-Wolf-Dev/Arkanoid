#ifndef BLOCK_H
#define BLOCK_H

#include "Vector2Di.h"

class Block
{
	char m_symbol = '-';
	int m_health;
	static int m_width;
	Vector2Di m_position;

public:
	Block(const Vector2Di& position) 
		: m_health { 1 }
		, m_position{ position }
	{
	};

	char getSymbol() const { return m_symbol; };
	int getHealth() const { return m_health; };
	static int getWidth();
	Vector2Di getPosition() const { return m_position; };

	void decreaseHealth() { --m_health; };
};

#endif // BLOCK_H
