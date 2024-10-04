#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"
#include <deque>

class Food {
public:
    Vector2 position;
    Texture2D texture;
    Food(std::deque<Vector2> snakeBody) {
        Image image = LoadImage("assets/apple.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);

        position = GenerateRandomPosition(snakeBody);
    }
    ~Food() {
        UnloadTexture(texture);
    }

    void Draw();
    Vector2 GenerateRandomPosition(std::deque<Vector2> snakeBody);
    Vector2 GenerateRandomCell();
};

#endif
