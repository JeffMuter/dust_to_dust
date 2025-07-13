#include <raylib.h>

int main() {

    typedef struct {
        int x, y, health;
    } Player;

    InitWindow(800, 450, "dust_to_dust");
    ToggleFullscreen();
    int scrWidth = GetScreenWidth();
    int scrHeight = GetScreenHeight();

    Player player = {scrWidth / 2, scrHeight / 2, 100};
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(player.x, player.y, 30, 30, RED);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
