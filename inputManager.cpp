#include "inputManager.h"

InputManager* InputManager::manager = nullptr;

InputManager *InputManager::GetInstance()
{
    if(manager==nullptr){
        manager = new InputManager();
    }
    return manager;
}

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

Vector2 InputManager::getMovement() {
    Vector2 movement = {0, 0};
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
        movement.y = -1;
    } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
        movement.y = 1;
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
        movement.x = 1;
    } else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
        movement.x = -1;
    }

    if (movement.x != 0 && movement.y) {
        movement.x *= 0.61f;
        movement.y *= 0.61f;
    }

    return movement;
}

bool InputManager::isInteracting() {
    if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_E) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        return true;
    }

    return false;
}

bool InputManager::isColliding(Rectangle a, Rectangle b) {
    if ((IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_E)) && CheckCollisionRecs(a, b)) {
        return true;
    }

    return false;
}

bool InputManager::isClickRect(Rectangle rect) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rect)) {
        return true;
    }

    return false;
}