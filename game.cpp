#include "game.h"
#include "raygui.h"
#include "scene.h"
#include "locationFactory.h"
#include "player.h"
#include "sceneManager.h"
#include "fontManager.h"
#include "soundManager.h"

// When set to true renders in-game debug options
#define DEBUG false

Game::Game()
{
    screenWidth = 800;
    screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Exercise Your Demons");
    SetTargetFPS(60);

    GuiSetFont(FontManager::GetInstance()->getFont());
    GuiSetStyle(DEFAULT, TEXT_SIZE, 18);
}

Game::~Game()
{
    CloseWindow();
}

void Game::update()
{
    SoundManager::GetInstance()->update();

    overlayScene = SceneManager::GetInstance()->getSceneOverlay();
    currentScene = SceneManager::GetInstance()->getCurrentScene();

    if (overlayScene != nullptr) {
        overlayScene->update();
        return;
    }

    currentScene->update();
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    currentScene->draw();

    if (overlayScene != nullptr) {
        overlayScene->draw();
    }

    DrawTextEx(FontManager::GetInstance()->getFontItal(), "@BoopDood", {(float)screenWidth - 130, (float)screenHeight - 35}, 18, FontManager::GetInstance()->getSpacing(), BLUE);

    if (DEBUG) {
        currentScene->debug();
        DrawFPS(screenWidth - 80, 10);
    }

    EndDrawing();
}

void Game::run() {
    update();
    draw();
}

bool Game::isRunning() {
    return WindowShouldClose() == false;
}