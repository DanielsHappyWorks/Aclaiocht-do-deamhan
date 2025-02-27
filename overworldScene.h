#pragma once
#include "scene.h"
#include "raylib.h"

class OverworldScene : public Scene {
    private:
        Texture2D background;
        
        Vector2 playerPos;
        float playerSpeed;
        float playerScale;
    public:
        OverworldScene();
        ~OverworldScene();
        void update();
        void draw();
        bool isDone();
        void debug();
};