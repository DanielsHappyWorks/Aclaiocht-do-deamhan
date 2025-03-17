#pragma once

class Scene {
    public:
        virtual bool isDone() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void debug() = 0;
};

class SceneOverlay : public Scene {
    public:
        virtual bool isDoneAtLoc() = 0;
};