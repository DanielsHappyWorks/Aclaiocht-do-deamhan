#include "game.h"
#include "raygui.h"
#include "scene.h"
#include "locationFactory.h"
#include "player.h"
#include "sceneManager.h"
#include "fontManager.h"
#include "soundManager.h"
#include "menuScene.h"
#include "mouseManager.h"

// When set to true renders in-game debug options
#define DEBUG false

Game::Game()
{
    screenWidth = 800;
    screenHeight = 600;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "Exercise Your Demons");
    Image icon = LoadImage("assets/images/icons/icon.png");
    SetWindowIcon(icon);

    target = LoadRenderTexture(screenWidth, screenHeight);

    SetTargetFPS(60);

    GuiSetFont(FontManager::GetInstance()->getFont());
    GuiSetStyle(DEFAULT, TEXT_SIZE, 18);
}

Game::~Game()
{
    UnloadRenderTexture(target);
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

    MouseManager::GetInstance()->update();
}

void Game::draw()
{
    // Stretch contents of the window
    BeginTextureMode(target);
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    currentScene->draw();

    if (overlayScene != nullptr) {
        overlayScene->draw();
    }

    if (SceneManager::GetInstance()->getSceneOverlay() == nullptr) {
        if (GuiButton((Rectangle){10, screenHeight - 30, 20, 20}, "#191#")) {
            SoundManager::GetInstance()->playSound(SFX_CLICK);
            SceneManager::GetInstance()->setSceneOverlay(new ControlsScene());
        }

        if (GuiButton((Rectangle){32, screenHeight - 30, 20, 20}, "#142#")) {
            SoundManager::GetInstance()->playSound(SFX_CLICK);
            SceneManager::GetInstance()->setSceneOverlay(new OptionsScene());
        }

        if (GuiButton((Rectangle){54, screenHeight - 30, 20, 20}, "#149#")) {
            SoundManager::GetInstance()->playSound(SFX_CLICK);
            SceneManager::GetInstance()->setSceneOverlay(new CreditsScene());
        }
    }

    MouseManager::GetInstance()->draw();

    if (DEBUG) {
        currentScene->debug();
        DrawFPS(screenWidth - 80, 10);
    }

    EndTextureMode();

    BeginDrawing();
        ClearBackground(RAYWHITE);
        //TODO figure out why the texture does not stretch properly
        // Draw the target texture to the screen, stretching it to fit the window
        DrawTexturePro(target.texture, (Rectangle){ 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Rectangle){ 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() }, (Vector2){ 0, 0 }, 0.0f, WHITE);
    EndDrawing();
}

void Game::run() {
    update();
    draw();
}

bool Game::isRunning() {
    return WindowShouldClose() == false;
}