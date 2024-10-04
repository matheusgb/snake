#ifndef GAME_H
#define GAME_H

#include "food.h"
#include "snake.h"

class Game {
public:
	Snake snake;
	Food food = Food(snake.body);

	void Draw();
	void Update();
	void CheckCollisionWithFood();
};

#endif
