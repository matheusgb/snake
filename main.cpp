#include <iostream>
#include "raylib.h"
#include "food.h"

Color white = { 238, 238, 238, 255 };
Color black = { 51, 51, 51, 255 };

int cellSize = 10;
int cellCount = 50;

int main() {
    int screenResolution = cellSize * cellCount;
    InitWindow(screenResolution, screenResolution, "snake");
    SetTargetFPS(60);

    Food food; // inicialização direta, disponível a partir do C++11. Assim inicializa o objeto com alocação automática (na pilha), com a memoria sendo liberada ao fim da função. Caso eu utilizasse 'new' nessa criação, seria alocação dinâmica (no heap), e eu teria que liberar a memória com o 'delete' para não haver memory leak. C++ não tem garbage collector por padrão.

    while (WindowShouldClose() == false) { // verifica se a tecla ESC ou o X da janela foi clicado
        BeginDrawing();

        ClearBackground(black);
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
