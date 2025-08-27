#pragma once
#include "rayxtend.h"

class MouseManager {
    protected:
        MouseManager();
        ~MouseManager();
        static MouseManager* manager;

    public:
        MouseManager(MouseManager &other) = delete;
        void operator=(const MouseManager &) = delete;
        static MouseManager *GetInstance();

        void update();
        void draw();
};