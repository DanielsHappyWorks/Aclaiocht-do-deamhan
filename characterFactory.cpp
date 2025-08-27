#include "characterFactory.h"
#include "narrativeSceneFactory.h"
#include "player.h"
#include "soundManager.h"
#include "inputManager.h"
#include "sceneManager.h"
#include "constants.h"

CharacterFactory* CharacterFactory::factory = nullptr;

CharacterFactory *CharacterFactory::GetInstance()
{
    if(factory==nullptr){
        factory = new CharacterFactory();
    }
    return factory;
}

CharacterFactory::CharacterFactory() {
    banshee = new Character(
        "Chaointe Doran",
        BANSHEE,
        SFX_DIALOG_FEMALE,
        {GYM, RESTAURANT, SHOP},
        {GYM, PUB, SHOP},
        "assets/images/characters/banshee/banshee_front.png",
        "assets/images/characters/banshee/banshee_side.png",
        {SCREEN_WIDTH/2, SCREEN_HEIGHT/2}
    );

    paddy = new Character(
        "St. Paddy",
        PADDY,
        SFX_DIALOG_MALE,
        {PUB},
        {PUB},
        "assets/images/characters/paddy/paddy_front.png",
        "assets/images/characters/paddy/paddy_side.png",
        {SCREEN_WIDTH - 200, 150}
    );

    pooka = new Character(
        "Púca Cleasaí",
        POOKA,
        SFX_DIALOG_MALE,
        {PUB, GYM, RESTAURANT},
        {SHOP, PUB, GYM},
        "assets/images/characters/pooka/pooka_front.png",
        "assets/images/characters/pooka/pooka_side.png",
        {SCREEN_WIDTH/2 + 75, SCREEN_HEIGHT/2}
    );

    dullahan = new Character(
        "Crom Dubh",
        DULLAHAN,
        SFX_DIALOG_FEMALE,
        {RESTAURANT, SHOP, GYM},
        {PUB, GYM, SHOP},
        "assets/images/characters/dullahan/dullahan_front.png",
        "assets/images/characters/dullahan/dullahan_side.png",
        {SCREEN_WIDTH/2 - 75, SCREEN_HEIGHT/2}
    );

    shopkeeper = new Character(
        "Shopkeeper",
        SHOPKEEPER,
        SFX_DIALOG_FEMALE,
        {SHOP},
        {SHOP},
        "assets/images/characters/side/sentra.png",
        "assets/images/characters/side/sentra.png",
        {SCREEN_WIDTH/2, 100}
    );

    cook = new Character(
        "Chef",
        CHEF,
        SFX_DIALOG_MALE,
        {RESTAURANT},
        {RESTAURANT},
        "assets/images/characters/side/supperwacks.png",
        "assets/images/characters/side/supperwacks.png",
        {200, 130}
    );
}

CharacterFactory::~CharacterFactory() {

}

std::list<Character*> CharacterFactory::getCharacters() {
    return {banshee, paddy, pooka, dullahan, shopkeeper, cook};
}

Character* CharacterFactory::getCharacter(CharEnum charEnum) {
    switch (charEnum) {
        case BANSHEE:
            return banshee;
        case PADDY:
            return paddy;
        case POOKA:
            return pooka;
        case DULLAHAN:
            return dullahan;
        case SHOPKEEPER:
            return shopkeeper;
        case CHEF:
            return cook;
        case PLAYER:
            return Player::GetInstance()->getCharacter();
        default:
            return nullptr;
    }
}

std::vector<Character*> CharacterFactory::getCharactersAtLoc(LocEnum loc) {
    std::vector<Character*> characters = {};
    for (Character* character : getCharacters()) {
        if (character->getCurrentLoc() == loc) {
            characters.push_back(character);
        }
    }

    return characters;
}

void CharacterFactory::playCharacterEvents(LocEnum loc, Rectangle playerRect) {
    std::vector<Character*> characters = CharacterFactory::GetInstance()->getCharactersAtLoc(loc);
    characters.push_back(Player::GetInstance()->getCharacter());

    for (Character* character : characters) {
        if (CharacterFactory::GetInstance()->isNarrativeSceneReady(character->getType())) {
            NarrativeScene* scene = CharacterFactory::GetInstance()->getNarrativeScene(character->getType());

            if (scene->isForced() || InputManager::GetInstance()->isIteractingWithCollider(playerRect, character->getCollisionRect())) {
                SceneManager::GetInstance()->setSceneOverlay(scene);
            }
        }
    }
}

bool CharacterFactory::isCoreSceneReady(CharEnum charEnum) {
    std::vector<NarrativeScene*> scenes = NarrativeSceneFactory::GetInstance()->getCharacterEvents(charEnum);

    for (NarrativeScene* scene : scenes)
    {
        if (scene->isReady() && !scene->isDone()) {
            return true;
        }
    }
    
    return false;
}

bool CharacterFactory::isNarrativeSceneReady(CharEnum charEnum) {
    return isCoreSceneReady(charEnum) || NarrativeSceneFactory::GetInstance()->getDefaultCharacterEvent(charEnum) != nullptr;
}

NarrativeScene* CharacterFactory::getNarrativeScene(CharEnum charEnum) {
    std::vector<NarrativeScene*> scenes = NarrativeSceneFactory::GetInstance()->getCharacterEvents(charEnum);

    for (NarrativeScene* scene : scenes)
    {
        if (scene->isReady() && !scene->isDone()) {
            return scene;
        }
    }
    
    return NarrativeSceneFactory::GetInstance()->getDefaultCharacterEvent(charEnum);
}