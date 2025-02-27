#include "overworldScene.h"
#include "player.h"
#include "inputManager.h"
#include "locationFactory.h"
#include "raymath.h"
#include "inputManager.h"
#include "locationScene.h"
#include "sceneManager.h"
#include <string>

OverworldScene::OverworldScene() {
    playerPos = {406, 218};
    playerSpeed = 160;
    playerScale = 0.35f;

    background = LoadTexture("assets/images/locations/map.png");
}

OverworldScene::~OverworldScene() {
    UnloadTexture(background);
}

void OverworldScene::update() {
    playerPos = Player::GetInstance()->move(playerPos, playerSpeed, playerScale);

    if (InputManager::GetInstance()->isInteracting()) {
        for (Location* loc : LocationFactory::GetInstance()->getLocations()) {
            if (CheckCollisionRecs(Player::GetInstance()->getCollisionRect(playerPos, playerScale), loc->getBuildingRect())) {
                SceneManager::GetInstance()->setCurrentScene(new LocationScene(loc));
            }
        }
    }
}

void OverworldScene::draw() {
    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);

    for (Location* loc : LocationFactory::GetInstance()->getLocations()) {
        loc->drawBuilding();
    }

    Player::GetInstance()->draw(playerPos, playerScale);
}

bool OverworldScene::isDone() {
    return false;
}

void OverworldScene::debug() {
    DrawRectangleLinesEx(Player::GetInstance()->getCollisionRect(playerPos, playerScale), 2.0f, GREEN);

    for (Location* loc : LocationFactory::GetInstance()->getLocations()) {
        DrawRectangleLinesEx(loc->getBuildingRect(), 2.0f, GREEN);
    }
}