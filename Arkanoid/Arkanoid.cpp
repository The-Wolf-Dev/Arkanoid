#include "Arkanoid.h"

#include<iostream>
#include<thread>

Arkanoid::Arkanoid()
	: m_field{ Field(24, 14) }
	, m_ball{ Ball({m_field.getWidth() / 2 - 1, m_field.getHeight() - 5}) }
	, m_plate{ Plate({m_field.getWidth() / 2 - 1, m_field.getHeight() - 4}) }
	, m_blocks {}
{
	int margin = 3;
	int start_x = margin, end_x = m_field.getWidth() - margin, start_y = margin, rows = 2;
	for (int i{ 0 }; i < rows; ++i) {
		for (; start_x < end_x; start_x += Block::getWidth()) {
			m_blocks.emplace_back(Vector2Di(start_x, start_y + i));
		}
		start_x = margin;
	}
};

void Arkanoid::start() {
	while (!gameOver) {
		m_field.draw();
		m_ball.move();
		m_plate.move();
		checkCollision();
		m_field.place(m_ball);
		m_field.place(m_plate);
		m_field.place(m_blocks);
		m_field.show();
		checkBlocksCount();

		//std::cout << m_ball.getPosition() << std::endl;
		//std::cout << m_plate.getPosition() << std::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
	std::cout << gameOverText << std::endl;
}

void Arkanoid::checkCollision() {
	checkBallCollision();
	checkPlateCollision();
}

void Arkanoid::checkBallCollision() {
	checkWallCollideWith(m_ball);
	checkBallCollideWith(m_blocks);
}

void Arkanoid::checkPlateCollision() {
	checkWallCollideWith(m_plate);
	checkPlateCollideWith(m_ball);
}

void Arkanoid::checkWallCollideWith(Ball& ball) {
	Vector2Di ballPosition = ball.getPosition();
	Vector2Di ballDirection = ball.getDirection();
	if (ballPosition.getX() == 1 && ballPosition.getY() == 1
		|| ballPosition.getX() == m_field.getWidth() - 2 && ballPosition.getY() == 1) {
		ball.setDirection(ballDirection.invert());
	}
	else if (ballPosition.getY() == m_field.getHeight() - 2) {
		//Vector2D new_direction = { ballDirection.getX(), ballDirection.getY() * -1 };
		//ball.setDirection(new_direction);
		gameOverText.append("You lost");
		gameOver = true;
	}
	else if (ballPosition.getX() == 1 || ballPosition.getX() == m_field.getWidth() - 2) {
		ball.setDirection(ballDirection.invertX());
	}
	else if (ballPosition.getY() == 1) {
		ball.setDirection(ballDirection.invertY());
	}
}

void Arkanoid::checkWallCollideWith(Plate& plate) {
	Vector2Di platePosition = plate.getPosition();
	if (platePosition.getX() == -1) {
		plate.setPosition({ m_field.getWidth() - 2, platePosition.getY() });
	}
	else if (platePosition.getX() + plate.getWidth() - 1 == m_field.getWidth()) {
		plate.setPosition({ 1, platePosition.getY() });
	}
}

void Arkanoid::checkPlateCollideWith(Ball& ball) {
	Vector2Di ballPosition = ball.getPosition();
	Vector2Di ballDirection = ball.getDirection();
	Vector2Di platePosition = m_plate.getPosition();
	int plateWidth = m_plate.getWidth();
	if (ballPosition.getY() == platePosition.getY() - 1
		&& ballPosition.getX() >= platePosition.getX() - 1
		&& ballPosition.getX() <= platePosition.getX() + plateWidth)
	{
		ball.setDirection(ballDirection.invertY());
	}
	else if (ballPosition.getY() == platePosition.getY() 
		&& (ballPosition.getX() == platePosition.getX() - 1 
			|| ballPosition.getX() == platePosition.getX() + plateWidth))
	{
		ball.setDirection(ballDirection.invertX());
	}
}

void Arkanoid::checkBallCollideWith(std::vector<Block>& blocks) {
	Vector2Di ballPosition = m_ball.getPosition();
	Vector2Di ballDirection = m_ball.getDirection();
	Vector2Di new_direction = ballDirection;
	int blockWidth = Block::getWidth();
	auto blocksSize = blocks.size();
	for (size_t i = 0; i < blocksSize; ++i) {
		auto &block = blocks[i];
		Vector2Di blockPosition = block.getPosition();
		if(ballPosition.getX() >= blockPosition.getX() - 1
			&& ballPosition.getX() <= blockPosition.getX() + blockWidth
			&& (ballPosition.getY() == blockPosition.getY() - 1
				|| ballPosition.getY() == blockPosition.getY() + 1))
		{
			new_direction = Vector2Di::invertY(ballDirection);
			block.decreaseHealth();
		}
		else if (ballPosition.getY() == blockPosition.getY()
			&& (ballPosition.getX() == blockPosition.getX() - 1
				|| ballPosition.getX() == blockPosition.getX() + blockWidth))
		{
			new_direction = Vector2Di::invertX(ballDirection);
			block.decreaseHealth();
		}
		
		if (ballDirection != new_direction) {
			if (block.getHealth() < 1) blocks.erase(blocks.begin() + i);
			m_ball.setDirection(new_direction);
			break;
		}
	}
}

void Arkanoid::checkBlocksCount() {
	if (m_blocks.size() == 0) {
		gameOverText.append("You won");
		gameOver = true;
	}
}