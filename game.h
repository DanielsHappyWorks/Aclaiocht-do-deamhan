#pragma once
#include "raylib.h"
#include "scene.h"

class Game {
    private:
        int screenWidth;
        int screenHeight;

        RenderTexture2D target;
        Vector2 mousePos;

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