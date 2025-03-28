#pragma once
#include "scene.h"
#include "location.h"
#include "raylib.h"

class LocationScene : public Scene {
    private:
        Location* location;
        
        Vector2 playerPos;
        float playerSpeed;
        float playerScale;

        bool done;

        Texture2D eventIcon;
    public:
        LocationScene(Location* location);
        ~LocationScene();
        void update();
        void draw();
        bool isDone();
        void debug();
};