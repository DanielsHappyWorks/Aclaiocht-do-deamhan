#include "game.h"
#include "raygui.h"
#include "characterSelectScene.h"
#include "player.h"

// When set to true renders in-game debug options
#define DEBUG false

Game::Game()
{
    screenWidth = 800;
    screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Exercise Your Demons");
    SetTargetFPS(60);

    showMessageBox = false;
    background = LoadTexture("assets/images/locations/map.png");
    gym = LoadTexture("assets/images/locations/gym.png");
    sentra = LoadTexture("assets/images/locations/sentra.png");
    supperwacks = LoadTexture("assets/images/locations/supperwacks.png");
    pub = LoadTexture("assets/images/locations/pub.png");

    currentScene = new CharacterSelectScene();
}

Game::~Game()
{
    UnloadTexture(background);
    UnloadTexture(gym);
    UnloadTexture(sentra);
    UnloadTexture(supperwacks);
    UnloadTexture(pub);
    CloseWindow();

    //TODO cleanup scene!!!!!
}

void Game::update()
{
    if (currentScene != nullptr) {
        currentScene->update();

        if (currentScene->isDone()) {
            currentScene = nullptr;
        }
    }
}

void Game::draw()
{
    BeginDrawing();
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    if (currentScene != nullptr) {
        currentScene->draw();
    } else {

        DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(gym, (Vector2){550, 20}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(sentra, (Vector2){70, 260}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(supperwacks, (Vector2){180, -30}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(pub, (Vector2){385, 320}, 0.0f, 1.0f, WHITE);
        DrawTextureEx(Player::GetInstance()->getCurrentSprite(), (Vector2){300, 200}, 0.0f, 0.35f, WHITE);

        if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

        if (showMessageBox)
        {
            int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
                "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

            if (result >= 0) showMessageBox = false;
        }
    }

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