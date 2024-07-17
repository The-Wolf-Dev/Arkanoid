#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "Ball.h"
#include "Plate.h"
#include "Block.h"

class Field
{
private:
	char m_filler { ' ' };
	int m_height;
	int m_width;
	char** m_field = nullptr;

	void init();
public:
	Field();
	Field(int height, int width);
	~Field();

	void draw();
	void show();
	void place(const Ball& ball);
	void place(const Plate& plate);
	void place(const std::vector<Block>& blocks);

	int getHeight() const;
	int getWidth() const;
};

#endif // FIELD_H