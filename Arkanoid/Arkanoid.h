#ifndef ARCANOID_H
#define ARCANOID_H

#include<vector>

#include "Field.h"
#include "Ball.h"
#include "Plate.h"
#include "Block.h"

class Arkanoid
{
	bool gameOver = false;
	Field m_field;
	Ball m_ball;
	Plate m_plate;
	std::vector<Block> m_blocks;
	std::string gameOverText = "Game over. ";

	void checkCollision();
	void checkBallCollision();
	void checkPlateCollision();
	void checkWallCollideWith(Ball& ball);
	void checkWallCollideWith(Plate& plate);
	void checkPlateCollideWith(Ball& ball);
	void checkBallCollideWith(std::vector<Block>& blocks);
	
	void checkBlocksCount();
public:
	Arkanoid();
	Arkanoid(const Arkanoid& arkanoid) = delete;
	Arkanoid(Arkanoid&& arkanoid) = delete;

	void start();
};

#endif // ARCANOID_H