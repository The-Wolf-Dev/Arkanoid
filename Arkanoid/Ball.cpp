#include "Ball.h"

void Ball::move() {
	m_position += m_direction;
}

void Ball::setDirection(const Vector2Di& new_direction) {
	m_direction = new_direction;
}

Vector2Di Ball::getDirection() const {
	return m_direction;
};

Vector2Di Ball::getPosition() const {
	return m_position;
};

char Ball::getSymbol() const {
	return m_symbol;
};