#ifndef GAME_H
#define GAME_H

#include "food.h"
#include "snake.h"

class Game {
public:
	Snake snake;
	Food food = Food(snake.body);
	bool running = true;

	void Draw();
	void Update();
	void CheckCollisionWithFood();
	void CheckCollisionWithEdges();
	void GameOver();
	void CheckCollisionWithTail();
};

#endif
