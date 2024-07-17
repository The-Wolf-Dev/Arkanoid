#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2Di
{
	int m_x;
	int m_y;
public:
	static Vector2Di ZERO;
	static Vector2Di LEFT;
	static Vector2Di RIGHT;
	static Vector2Di UP_LEFT;
	static Vector2Di UP_RIGHT;
	static Vector2Di DOWN_LEFT;
	static Vector2Di DOWN_RIGHT;

	Vector2Di() : Vector2Di::Vector2Di(0, 0) {};
	Vector2Di(int x, int y) : m_x{ x }, m_y{ y } {};
	Vector2Di(const Vector2Di& vector2d) = default;

	int getX() const { return m_x; };
	int getY() const { return m_y; };
	void setX(const int x) { m_x = x; };
	void setY(const int y) { m_y = y; };

	Vector2Di& invertX();
	Vector2Di& invertY();
	Vector2Di& invert();
	
	static Vector2Di invertX(const Vector2Di& vec2di);
	static Vector2Di invertY(const Vector2Di& vec2di);
	static Vector2Di invert(const Vector2Di& vec2di);

	Vector2Di& operator+=(const Vector2Di& rhs);
	Vector2Di& operator*(const int& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Vector2Di& vector2d);
	bool operator!=(const Vector2Di& rhs);
};

#endif // VECTOR2D_H