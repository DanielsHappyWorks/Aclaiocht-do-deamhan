#pragma once
#include "scene.h"

class OptionsScene : public SceneOverlay {
    private:
        bool done = false;
        float volume;
        float volumeSound;
        float volumeMusic;
    public:
        OptionsScene();
        ~OptionsScene();
        void update();
        void draw();
        bool isDone();
        bool isDoneAtLoc();
        void debug();
};

class ControlsScene : public SceneOverlay {
    private:
        bool done = false;
    public:
        ControlsScene();
        ~ControlsScene();
        void update();
        void draw();
        bool isDone();
        bool isDoneAtLoc();
        void debug();
};

class CreditsScene : public SceneOverlay {
    private:
        bool done = false;
    public:
        CreditsScene();
        ~CreditsScene();
        void update();
        void draw();
        bool isDone();
        bool isDoneAtLoc();
        void debug();
};