#include <raylib.h>

int main() {

    typedef struct {
        int x, y, health;
    } Player;

    typedef enum {
        TILE_GRASS,
        TILE_WATER,
        TILE_BRICK,
        TILE_NPC,
        TILE_GOBLIN,
    } TileType;

    typedef struct {
        TileType tiles[40][60];
        int x, y; // global map location
    } Screen;

    typedef struct {
        Screen screens[4][4];
    } Map;

    InitWindow(800, 450, "dust_to_dust");
    ToggleFullscreen();
    int scrWidth = GetScreenWidth();
    int scrHeight = GetScreenHeight();

    Player player = {scrWidth / 2, scrHeight / 2, 100};
    
    while (!WindowShouldClose()) {
        // controls go here
        if (IsKeyPressed(KEY_W)) {
            player.y = player.y - 30;
        }
        if (IsKeyPressed(KEY_S)) {
            player.y = player.y + 30;
        }
        if (IsKeyPressed(KEY_A)) {
            player.x = player.x - 30;
        }
        if (IsKeyPressed(KEY_D)) {
            player.x = player.x + 30;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(player.x, player.y, 30, 30, RED);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
