#include "locationScene.h"
#include "player.h"
#include "inputManager.h"
#include "raymath.h"
#include <string>

LocationScene::LocationScene(Location* location) {
    this->location = location;
    this->done = false;
    playerPos = {406, 218};
    playerSpeed = 160;
    playerScale = 0.7f;
}

LocationScene::~LocationScene() {

}

void LocationScene::update() {
    playerPos = Player::GetInstance()->move(playerPos, playerSpeed, playerScale);

    if (InputManager::GetInstance()->isInteracting() && CheckCollisionRecs(Player::GetInstance()->getCollisionRect(playerPos, playerScale), location->getExit())) {
        done = true;
    }
}

void LocationScene::draw() {
    location->drawInterior();
    Player::GetInstance()->draw(playerPos, playerScale);
}

bool LocationScene::isDone() {
    return done;
}

void LocationScene::debug() {
    DrawRectangleLinesEx(Player::GetInstance()->getCollisionRect(playerPos, playerScale), 2.0f, GREEN);
    DrawRectangleLinesEx(location->getExit(), 2.0f, GREEN);
}