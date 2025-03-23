#include "endOfDemoScene.h"
#include "fontManager.h"

EndOfDemoScene::EndOfDemoScene() {
    background = LoadTexture("assets/images/locations/char_sel.png");
}

EndOfDemoScene::~EndOfDemoScene() {
    UnloadTexture(background);
}

void EndOfDemoScene::update() {
}

void EndOfDemoScene::draw() {

    DrawTextureEx(background, {0, 0}, 0.0f, 1.0f, WHITE);

    std::string text = "Thank You For Playing The DEMO!";
    float textCenter = MeasureTextEx(FontManager::GetInstance()->getFontHeaders(), text.c_str(), 40, FontManager::GetInstance()->getSpacing()).x/2;
    DrawTextEx(FontManager::GetInstance()->getFontHeaders(), text.c_str(), {(float)GetScreenWidth()/2 - textCenter, (float)GetScreenHeight()/2 - 40}, 40, FontManager::GetInstance()->getSpacing(), DARKGREEN);

    std::string text_exit = "Press Esc to Exit";
    float textCenter_exit = MeasureTextEx(FontManager::GetInstance()->getFont(), text_exit.c_str(), 25, FontManager::GetInstance()->getSpacing()).x/2;
    DrawTextEx(FontManager::GetInstance()->getFont(), text_exit.c_str(), {(float)GetScreenWidth()/2 - textCenter_exit, (float)GetScreenHeight()/2 + 20}, 25, FontManager::GetInstance()->getSpacing(), DARKGREEN);
}

bool EndOfDemoScene::isDone() {
    return false;
}

void EndOfDemoScene::debug() {}

