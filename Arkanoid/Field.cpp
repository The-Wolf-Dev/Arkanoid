#include <iostream>
#include "Field.h"
#include "Block.h"


Field::Field(): Field::Field(20, 20) {
}

Field::Field(int height, int width)
	: m_height{ height + 2 }, m_width{ width + 2 } {
	m_field = new char* [m_height];

	for (int i = 0; i < m_height; i++)
		m_field[i] = new char[m_width];

	init();
}

Field::~Field() {
	for (int i = 0; i < m_height; i++)
		delete[] m_field[i];

	delete[] m_field;
}

void Field::show() {
	system("cls");
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++)
			std::cout << m_field[i][j] << " ";

		std::cout << std::endl;
	}
}

void Field::place(const Ball& ball) {
	auto ballPosition = ball.getPosition();
	m_field[ballPosition.getY()][ballPosition.getX()] = ball.getSymbol();
}

void Field::place(const Plate& plate) {
	auto platePosition = plate.getPosition();
	unsigned plateWidth = plate.getWidth();
	for (size_t i = 0; i < plateWidth; ++i) {
		if (platePosition.getX() + i > 0 && platePosition.getX() + i < m_width - 1) {
			m_field[platePosition.getY()][platePosition.getX() + i] = plate.getSymbol();
		}
	}
}

void Field::place(const std::vector<Block>& blocks) {
	auto blockWidth = Block::getWidth();
	for (const auto &block: blocks) {
		auto blockPosition = block.getPosition();
		for (size_t i = 0; i < blockWidth; ++i) {
			m_field[blockPosition.getY()][blockPosition.getX() + i] = block.getSymbol();
		}
	}
}

int Field::getHeight() const {
	return m_height;
};

int Field::getWidth() const {
	return m_width;
};

void Field::init() {
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			if ((i == 0 || i == m_height - 1) && (j == 0 || j == m_width - 1)) m_field[i][j] = '+';
			else if (i == 0 || i == m_height - 1) m_field[i][j] = '-';
			else if (j == 0 || j == m_width - 1) m_field[i][j] = '|';
			else m_field[i][j] = m_filler;
		}
	}
};

void Field::draw() {
	for (int i = 1; i < m_height - 1; i++) {
		for (int j = 1; j < m_width - 1; j++) {
			m_field[i][j] = m_filler;
		}
	}
};