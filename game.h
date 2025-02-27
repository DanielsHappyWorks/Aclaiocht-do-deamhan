#pragma once
#include "raylib.h"
#include "scene.h"

class Game {
    private:
        int screenWidth;
        int screenHeight;

        Scene* currentScene;
        Scene* overlayScene;

        void update();
        void draw();
    public:
        Game();
        ~Game();
        bool isRunning();
        void run();
};