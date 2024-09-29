#include <iostream>
#include "raylib.h"

Color white = { 238, 238, 238, 255 };
Color black = { 51, 51, 51, 255 };

int main() {
    InitWindow(500, 500, "snake");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) { // verifica se a tecla ESC ou o X da janela foi clicado
        BeginDrawing();

        ClearBackground(white);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
