#include "game.h"
#include "raygui.h"
#include "scene.h"
#include "locationFactory.h"
#include "player.h"
#include "sceneManager.h"

// When set to true renders in-game debug options
#define DEBUG true

Game::Game()
{
    screenWidth = 800;
    screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Exercise Your Demons");
    SetTargetFPS(60);
}

Game::~Game()
{
    CloseWindow();

    //TODO cleanup?
}

void Game::update()
{
    //TODO migrate this to scene manager!
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

    DrawText("@BoopDood", screenWidth - 130, screenHeight - 35, 20, BLUE);

    if (DEBUG) {
        currentScene->debug();
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