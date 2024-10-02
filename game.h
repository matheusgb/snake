#ifndef GAME_H
#define GAME_H

#include "food.h"
#include "snake.h"

class Game {
public:
	Snake snake;
	Food food;

	void Draw();
	void Update();
};

#endif
