#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include <deque>

class Snake {
public:
	std::deque<Vector2> body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	void Draw();
};

#endif
