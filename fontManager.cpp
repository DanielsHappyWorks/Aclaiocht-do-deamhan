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
    font = LoadFontEx("./assets/fonts/eringobragh/eringobragh.ttf", 22, 0, 250);
    fontItal = LoadFontEx("./assets/fonts/eringobragh/eringobraghi.ttf", 22, 0, 250);
    fontHeaders = LoadFontEx("./assets/fonts/vinque/vinque.ttf", 32, 0, 250);
}

FontManager::~FontManager() {
    UnloadFont(font);
    UnloadFont(fontItal);
    UnloadFont(fontHeaders);
}

Font FontManager::getFont() {
    return font;
}

Font FontManager::getFontItal() {
    return fontItal;
}

Font FontManager::getFontHeaders() {
    return fontHeaders;
}

float FontManager::getSpacing() {
    return 2;
}