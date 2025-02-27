#include "game.h"
#include "raygui.h"
#include "characterSelectScene.h"
#include "overworldScene.h"
#include "locationScene.h"
#include "locationFactory.h"
#include "player.h"

// When set to true renders in-game debug options
#define DEBUG false

Game::Game()
{
    screenWidth = 800;
    screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Exercise Your Demons");
    SetTargetFPS(60);

    defaultScene = new OverworldScene();
    currentScene = new CharacterSelectScene();
    nextScene = new LocationScene(LocationFactory::GetInstance()->getByType("Gym"));
}

Game::~Game()
{
    CloseWindow();

    //TODO cleanup scene!!!!!
}

void Game::update()
{
    if (currentScene != nullptr) {
        currentScene->update();

        if (currentScene->isDone() && nextScene != nullptr) {
            currentScene = nextScene;
            nextScene = nullptr;
        }
        if (currentScene->isDone()) {
            currentScene = defaultScene;
        }
    }
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    currentScene->draw();

    DrawText("@BoopDood", screenWidth - 130, screenHeight - 35, 20, BLUE);

    if (DEBUG) {
        //TODO draw any debug tools
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