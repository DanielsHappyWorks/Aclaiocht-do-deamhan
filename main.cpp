#include "game.h"

// See https://github.com/raysan5/raygui
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main()
{
    Game game = Game();

    while (game.isRunning())
    {
        game.run();
    }

    return 0;
}