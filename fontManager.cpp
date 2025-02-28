#include "fontManager.h"

FontManager* FontManager::manager = nullptr;

FontManager *FontManager::GetInstance()
{
    if(manager==nullptr){
        manager = new FontManager();
    }
    return manager;
}

FontManager::FontManager() {
    font = LoadFont("resources/fonts/mecha.png");
}

FontManager::~FontManager() {
    UnloadFont(font);
}

Font FontManager::getFont() {
    return font;
}

float FontManager::getSpacing() {
    return 2;
}