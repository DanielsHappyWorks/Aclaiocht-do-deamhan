#pragma once
#include "scene.h"
#include "location.h"
#include "raylib.h"

class EndOfDemoScene : public Scene {
    private:
        Texture2D background;
    public:
        EndOfDemoScene();
        ~EndOfDemoScene();
        void update();
        void draw();
        bool isDone();
        void debug();
};