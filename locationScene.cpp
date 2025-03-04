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

    if (InputManager::GetInstance()->isInteracting()) {
        //TODO why do we fall in here when pressing on the banshee?
        if (CheckCollisionRecs(Player::GetInstance()->getCollisionRect(playerPos, playerScale), location->getExit()) || InputManager::GetInstance()->isClickRect(location->getExit())) {
            done = true;
        }

        std::vector<Character*> characters = CharacterFactory::GetInstance()->getCharactersAtLoc(location->getType());
        for (Character* character : characters) {
            if (CharacterFactory::GetInstance()->isNarrativeSceneReady(character->getType()) && CheckCollisionRecs(Player::GetInstance()->getCollisionRect(playerPos, playerScale), character->getCollisionRect(0.7f)) || InputManager::GetInstance()->isClickRect(character->getCollisionRect(0.7f))) {
                SceneManager::GetInstance()->setSceneOverlay(CharacterFactory::GetInstance()->getNarrativeScene(character->getType()));
                //hack to fix banshee click!
                done = false;
            }
        }
    }

    location->playAnyForcedEvents();
}

void LocationScene::draw() {
    location->drawInterior();

    std::vector<Character*> characters = CharacterFactory::GetInstance()->getCharactersAtLoc(location->getType());
    for (Character* character : characters) {
        DrawTextureFromCentre(character->getFront(), character->getPosAtLoc(location->getType()), 0.7f, 0.0f, WHITE);
    }

    Player::GetInstance()->draw(playerPos, playerScale);
}

bool LocationScene::isDone() {
    return done;
}

void LocationScene::debug() {
    std::vector<Character*> characters = CharacterFactory::GetInstance()->getCharactersAtLoc(location->getType());
    for (Character* character : characters) {
        DrawRectangleLinesEx(character->getCollisionRect(0.7f), 2.0f, GREEN);
    }
    DrawRectangleLinesEx(Player::GetInstance()->getCollisionRect(playerPos, playerScale), 2.0f, GREEN);
    DrawRectangleLinesEx(location->getExit(), 2.0f, GREEN);
}