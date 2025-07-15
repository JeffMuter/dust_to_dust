#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

    typedef enum {
        TILE_GRASS,
        TILE_WATER,
        TILE_BRICK,
        TILE_NPC,
        TILE_GOBLIN,
    } TileType;

    typedef struct {
        TileType tiles[8][12];
        int x, y; // global map location
    } Screen;

    typedef struct {
        Screen screens[4][4];
    } Map;

    typedef struct {
        int x, y, health;
    } Player;

Map* initMap(){
    // make a map, by making each individual screen via files in the /maps directory.
    // each file is a  grid of numbers. so we'll get each file, and read the contents
    // into the 'screens'. ez pz
    
    Map* map = malloc(sizeof(Map));
//    Screen screen  = {0};

    struct dirent *de; // pointer to directory entry
    DIR  *dr = opendir("../maps/");

    if (dr == NULL) {
        printf("could not open maps directory for file loading");
        return map;
    }

    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);

    closedir(dr);    
    return map;
}


int main() {
    
    Map* map = initMap();
    if (!map) {
        return 0;
    }

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

