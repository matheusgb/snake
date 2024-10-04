#include "game.h"
#include "raymath.h"

void Game::Draw() {
    food.Draw();
    snake.Draw();
}

void Game::Update() {
    snake.Update();
    CheckCollisionWithFood();
}

void Game::CheckCollisionWithFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
        food.position = food.GenerateRandomPosition(snake.body);
        snake.addSegment = true;
    }
}