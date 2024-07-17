#ifndef BALL_H
#define BALL_H

#include "Vector2Di.h"

class Ball
{
	char m_symbol { 'o' };
	Vector2Di m_direction{Vector2Di(-1, -1)};
	Vector2Di m_position;
	
public:
	Ball(const Vector2Di& position) : m_position{ position } {};

	void move();

	void setDirection(const Vector2Di&);
	Vector2Di getDirection() const;
	Vector2Di getPosition() const;
	char getSymbol() const;
};

#endif // BALL_H