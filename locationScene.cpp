#include "locationScene.h"
#include "player.h"
#include "inputManager.h"
#include "raymath.h"
#include <string>
#include "characterFactory.h"
#include "sceneManager.h"

LocationScene::LocationScene(Location* location) {
    this->location = location;
    this->done = false;
    playerPos = location->getPlayerStart();
    playerSpeed = 210;
    playerScale = 0.7f;
}

LocationScene::~LocationScene() {

}

void LocationScene::update() {
    playerPos = Player::GetInstance()->move(playerPos, playerSpeed, playerScale);

    Rectangle playerRect = Player::GetInstance()->getCollisionRect(playerPos, playerScale);

    if (InputManager::GetInstance()->isIteractingWithCollider(playerRect, location->getExit())) {
            done = true;
    }

    location->playAnyForcedEvents();

    CharacterFactory::GetInstance()->playCharacterEvents(location->getType(), playerRect);
}

void LocationScene::draw() {
    location->drawInterior();

    std::vector<Character*> characters = CharacterFactory::GetInstance()->getCharactersAtLoc(location->getType());
    for (Character* character : characters) {
        character->drawAtLoc();
    }

    Player::GetInstance()->draw(playerPos, playerScale);
}

bool LocationScene::isDone() {
    return done;
}

void LocationScene::debug() {
    std::vector<Character*> characters = CharacterFactory::GetInstance()->getCharactersAtLoc(location->getType());
    for (Character* character : characters) {
        DrawRectangleLinesEx(character->getCollisionRect(), 2.0f, GREEN);
    }
    DrawRectangleLinesEx(Player::GetInstance()->getCollisionRect(playerPos, playerScale), 2.0f, GREEN);
    DrawRectangleLinesEx(location->getExit(), 2.0f, GREEN);
}