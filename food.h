#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"

class Food {
public:
    Vector2 position;
    Texture2D texture;
    Food() {
        Image image = LoadImage("assets/apple.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);

        position = GenerateRandomPosition();
    }
    ~Food() {
        UnloadTexture(texture);
    }

    void Draw();
    Vector2 GenerateRandomPosition();
};

#endif
