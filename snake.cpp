#include "snake.h"
#include "raylib.h"

extern float cellSize;
extern int cellCount;
extern Color white;

void Snake::Draw() {
    for (unsigned int i = 0; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{ x * cellSize, y * cellSize, cellSize, cellSize };
        DrawRectangleRounded(segment, 0.5, 6, white);
    }
}