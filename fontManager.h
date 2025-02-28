#pragma once
#include "raylib.h"

class FontManager {
    protected:
        FontManager();
        ~FontManager();
        static FontManager* manager;

        Font font;
    public:
        FontManager(FontManager &other) = delete;
        void operator=(const FontManager &) = delete;
        static FontManager *GetInstance();

        Font getFont();
        float getSpacing();
};