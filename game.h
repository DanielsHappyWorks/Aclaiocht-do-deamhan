#pragma once
#include "raylib.h"
#include "scene.h"

class Game {
    private:
        int screenWidth;
        int screenHeight;

        Scene* defaultScene;
        Scene* currentScene;
        Scene* nextScene;

        void update();
        void draw();
    public:
        Game();
        ~Game();
        bool isRunning();
        void run();
};