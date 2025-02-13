#pragma once
#include "raylib.h"

class Game {
    private:
        int screenWidth;
        int screenHeight;
        bool showMessageBox;
        Texture2D background;
        Texture2D gym;
        Texture2D sentra;
        Texture2D supperwacks;
        Texture2D pub;

        Texture2D player;

        void update();
        void draw();
    public:
        Game();
        ~Game();
        bool isRunning();
        void run();
};