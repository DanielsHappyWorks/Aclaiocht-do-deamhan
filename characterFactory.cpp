#include "characterFactory.h"
#include "narrativeSceneFactory.h"
#include "player.h"

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
        {GYM, RESTAURANT, SHOP},
        {GYM, PUB, SHOP},
        "assets/images/characters/banshee/banshee_front.png",
        "assets/images/characters/banshee/banshee_side.png"
    );

    paddy = new Character(
        "St. Paddy",
        PADDY,
        {PUB},
        {PUB},
        "assets/images/characters/paddy/paddy_front.png",
        "assets/images/characters/paddy/paddy_side.png"
    );

    pooka = new Character(
        "Púca Cleasaí",
        POOKA,
        {PUB, GYM, RESTAURANT},
        {SHOP, GYM, PUB},
        "assets/images/characters/pooka/pooka_front.png",
        "assets/images/characters/pooka/pooka_side.png"
    );

    dullahan = new Character(
        "Crom Dubh",
        DULLAHAN,
        {RESTAURANT, SHOP, GYM},
        {PUB, SHOP, GYM},
        "assets/images/characters/dullahan/dullahan_front.png",
        "assets/images/characters/dullahan/dullahan_side.png"
    );
}

CharacterFactory::~CharacterFactory() {

}

std::list<Character*> CharacterFactory::getCharacters() {
    return {banshee, paddy, pooka, dullahan};
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
        case PLAYER:
            return Player::GetInstance()->getCharacter();
        default:
            return nullptr;
    }
}