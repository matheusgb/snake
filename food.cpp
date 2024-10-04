#include "food.h"
#include "raylib.h"
#include "main.h"
#include <deque>

extern float cellSize;
extern int cellCount;

void Food::Draw() {
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}

Vector2 Food::GenerateRandomCell() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{ x,y };
}

Vector2 Food::GenerateRandomPosition(std::deque<Vector2> snakeBody) {
    Vector2 position = GenerateRandomCell();
    while (ElementInDeque(position, snakeBody)) {
        position = GenerateRandomCell();
    }
    return position;
}