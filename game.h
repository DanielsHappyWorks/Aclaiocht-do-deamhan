#pragma once
#include "raylib.h"
#include "scene.h"

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

        Scene* currentScene;

        void update();
        void draw();
    public:
        Game();
        ~Game();
        bool isRunning();
        void run();
};