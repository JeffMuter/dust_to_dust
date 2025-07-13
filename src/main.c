#include <raylib.h>

int main() {
    InitWindow(800, 450, "Hello Raylib");
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello, Raylib!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
