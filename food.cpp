#include "food.h"
#include "raylib.h"

extern float cellSize;
extern int cellCount;

void Food::Draw() {
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
}

Vector2 Food::GenerateRandomPosition() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{ x,y };
}