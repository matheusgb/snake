#include "game.h"
#include "raymath.h"
#include <deque>
#include "main.h"

extern int cellCount;

void Game::Draw() {
    food.Draw();
    snake.Draw();
}

void Game::Update() {
    if (running) {
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
    }
}

void Game::CheckCollisionWithFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
        food.position = food.GenerateRandomPosition(snake.body);
        snake.addSegment = true;
    }
}

void Game::CheckCollisionWithEdges() {
    if (snake.body[0].x == cellCount || snake.body[0].x == -1) {
        GameOver();
    }
    if (snake.body[0].y == cellCount || snake.body[0].y == -1) {
        GameOver();
    }

}

void Game::GameOver() {
    snake.Reset();
    food.position = food.GenerateRandomPosition(snake.body);
    running = false;
}

void Game::CheckCollisionWithTail() {
    std::deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if (ElementInDeque(snake.body[0], headlessBody)) {
        GameOver();
    }
}