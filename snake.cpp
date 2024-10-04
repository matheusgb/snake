#include "snake.h"
#include "raylib.h"
#include "raymath.h"

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

void Snake::Update() {
    body.push_front(Vector2Add(body[0], direction)); // adiciona valor para guiar a direção da snake
    if (addSegment == true) {
        addSegment = false;
    } else {
        body.pop_back();
    }
}

void Snake::Reset() {
    body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
    direction = { 1,0 };
}