#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "food.h"
#include "snake.h"
#include "game.h"
#include "main.h"

Color white = { 238, 238, 238, 255 };
Color black = { 51, 51, 51, 255 };

float cellSize = 16;
int cellCount = 25;

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}

int main() {
    int screenResolution = cellSize * cellCount;
    InitWindow(screenResolution, screenResolution, "snake");
    SetTargetFPS(60);

    Game game; // inicialização direta, disponível a partir do C++11. Assim inicializa o objeto com alocação automática (na pilha), com a memoria sendo liberada ao fim da função. Caso eu utilizasse 'new' nessa criação, seria alocação dinâmica (no heap), e eu teria que liberar a memória com o 'delete' para não haver memory leak. C++ não tem garbage collector por padrão.

    while (WindowShouldClose() == false) { // verifica se a tecla ESC ou o X da janela foi clicado
        BeginDrawing();

        if (EventTriggered(0.1)) {
            game.Update();
        } 

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
            game.snake.direction = { 0, -1 };
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
            game.snake.direction = { 0, 1 };
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
            game.snake.direction = { -1, 0 };
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
            game.snake.direction = { 1, 0 };
        }

        ClearBackground(black);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
