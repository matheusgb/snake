#include "game.h"


void Game::Draw() {
    food.Draw();
    snake.Draw();
}

void Game::Update() {
    //food.Update();
    snake.Update();

}