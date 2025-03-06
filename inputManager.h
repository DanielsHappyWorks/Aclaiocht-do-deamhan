#pragma once
#include <string>
#include "raylib.h"

class InputManager {
    protected:
        InputManager();
        ~InputManager();
        static InputManager* manager;
    public:
        InputManager(InputManager &other) = delete;
        void operator=(const InputManager &) = delete;
        static InputManager *GetInstance();

        Vector2 getMovement();
        bool isInteracting();
        bool isColliding(Rectangle a, Rectangle b);
        bool isClickRect(Rectangle rect);
};