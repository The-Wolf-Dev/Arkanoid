#include "Vector2Di.h"

Vector2Di Vector2Di::ZERO = { 0, 0 };
Vector2Di Vector2Di::LEFT = { -1, 0 };
Vector2Di Vector2Di::RIGHT = { 1, 0 };
Vector2Di Vector2Di::UP_LEFT = { -1, -1 };
Vector2Di Vector2Di::UP_RIGHT = { 1, -1 };
Vector2Di Vector2Di::DOWN_LEFT = { -1, 1 };
Vector2Di Vector2Di::DOWN_RIGHT = { 1, 1 };

Vector2Di& Vector2Di::invertX() {
	m_x = -m_x;
	return *this;
}

Vector2Di& Vector2Di::invertY() {
	m_y = -m_y;
	return *this;
}

Vector2Di& Vector2Di::invert() {
	m_x = -m_x;
	m_y = -m_y;
	return *this;
}

Vector2Di Vector2Di::invertX(const Vector2Di& vec2di) {
	return { -vec2di.getX(), vec2di.getY() };
}

Vector2Di Vector2Di::invertY(const Vector2Di& vec2di) {
	return { vec2di.getX(), -vec2di.getY() };
}

Vector2Di Vector2Di::invert(const Vector2Di& vec2di) {
	return { -vec2di.getX(), -vec2di.getY() };
}

Vector2Di& Vector2Di::operator+=(const Vector2Di& rhs) {
	m_x += rhs.getX();
	m_y += rhs.getY();
	return *this;
};

bool Vector2Di::operator!=(const Vector2Di& rhs) {
	return this->getX() != rhs.getX() || this->getY() != rhs.getY();
}

Vector2Di& Vector2Di::operator*(const int& rhs) {
	m_x *= rhs;
	m_y *= rhs;
	return *this;
};

std::ostream& operator<<(std::ostream& os, const Vector2Di& vector2d) {
	os << "(" << vector2d.m_x << " " << vector2d.m_y << ")";
	return os;
};