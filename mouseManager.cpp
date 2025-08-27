#include "mouseManager.h"
#include "raygui.h"

MouseManager* MouseManager::manager = nullptr;

MouseManager *MouseManager::GetInstance()
{
    if(manager==nullptr){
        manager = new MouseManager();
    }
    return manager;
}

MouseManager::MouseManager() {
    HideCursor();
}

MouseManager::~MouseManager() {
}

void MouseManager::update() {
}

void MouseManager::draw() {
    Vector2 mousePos = GetMousePosition();
    GuiLabel((Rectangle){ mousePos.x, mousePos.y, 20, 20 }, "#20#");
}