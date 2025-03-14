#pragma once
#include "raylib.h"

class FontManager {
    protected:
        FontManager();
        ~FontManager();
        static FontManager* manager;

        Font font;
        Font fontItal;
        Font fontHeaders;
    public:
        FontManager(FontManager &other) = delete;
        void operator=(const FontManager &) = delete;
        static FontManager *GetInstance();

        Font getFont();
        Font getFontItal();
        Font getFontHeaders();
        float getSpacing();
};