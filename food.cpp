#include "food.h"
#include "raylib.h"

extern int cellSize;
extern Color white;

void Food::Draw() {
    DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, white);
}
