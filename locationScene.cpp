#include "locationScene.h"
#include "player.h"
#include "inputManager.h"
#include "raymath.h"
#include <string>

LocationScene::LocationScene(Location* location) {
    this->location = location;
    playerPos = {406, 218};
    playerSpeed = 160;
    playerScale = 0.7f;
}

LocationScene::~LocationScene() {

}

void LocationScene::update() {
    Vector2 movement = InputManager::GetInstance()->getMovement();
    movement = Vector2Scale(movement, playerSpeed);
    movement = Vector2Scale(movement, GetFrameTime());

    Vector2 nextPos = Vector2Add(playerPos, movement);

    if (nextPos.x <= 0) {
        nextPos.x = 0;
    }

    if (nextPos.y <= 0) {
        nextPos.y = 0;
    }

    Texture2D playerSprite = Player::GetInstance()->getCurrentSprite();

    if (nextPos.x >= GetScreenWidth() - playerSprite.width * playerScale) {
        nextPos.x = GetScreenWidth() - playerSprite.width * playerScale;
    }

    if (nextPos.y >= GetScreenHeight() - playerSprite.height * playerScale) {
        nextPos.y = GetScreenHeight() - playerSprite.height * playerScale;
    }

    Player::GetInstance()->animateCharacter(movement, playerPos, nextPos);

    if (nextPos.x != 0) {
        playerPos = nextPos;
    }
}

void LocationScene::draw() {
    location->drawInterior();
    DrawTextureEx(Player::GetInstance()->getCurrentSprite(), playerPos, 0.0f, playerScale, WHITE);
}

bool LocationScene::isDone() {
    return false;
}