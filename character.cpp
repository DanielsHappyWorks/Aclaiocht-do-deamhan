#include "character.h"
#include "gameState.h"

Character::Character(std::string name, CharEnum type, SFX sound, std::vector<LocEnum> dayLocations, std::vector<LocEnum> nightLocations, std::string front, std::string side) {
    this->name = name;
    this->type = type;
    this->sound = sound;
    this->dayLocations = dayLocations;
    this->nightLocations = nightLocations;
    this->front = LoadTexture(front.c_str());
    this->side = LoadTexture(side.c_str());
    this->choices = {};
    this->friendship = 0;
}

PlayerCharacter::PlayerCharacter(std::string name, CharEnum type, SFX sound, std::string front, std::string side) : Character{name, type, sound, {}, {}, front, side} {
}

Character::~Character() {
    UnloadTexture(front);
    UnloadTexture(side);
}
Texture2D Character::getFront() {
    return front;
}
Texture2D Character::getSide() {
    return side;
}
std::string Character::getName() {
    return name;
}
CharEnum Character::getType() { 
    return type;
}
SFX Character::getSound() {
    return sound;
}
LocEnum Character::getCurrentLoc() {
    int day = GameState::GetInstance()->getDay();

    if (GameState::GetInstance()->getTime() == NIGHT) {
        return nightLocations[day % nightLocations.size()];
    }

    return dayLocations[day % dayLocations.size()];
}

LocEnum PlayerCharacter::getCurrentLoc() {
    return MAP;
}

void Character::drawAtLoc() {
    DrawTextureFromCentre(getFront(), getPosAtLoc(getCurrentLoc()), 0.7f, 0.0f, WHITE);
}

CharDialogChoices Character::getChoice(int index) {
    if (choices.size() <= index) {
        return UNKNOWN;
    }

    return choices[index];
}

void Character::addChoice(CharDialogChoices choice) {
    choices.push_back(choice);
}

int Character::getFriendship() {
    return friendship;
}

//TODO fix locations & and make this per character configurable
Vector2 Character::getPosAtLoc(LocEnum loc) {
    switch (loc) {
        case PUB:
            return {GetScreenWidth()/2, GetScreenHeight()/2};
        case SHOP:
            return {GetScreenWidth()/2, GetScreenHeight()/2};
        case RESTAURANT:
            return {GetScreenWidth()/2, GetScreenHeight()/2};
        case GYM:
            return {GetScreenWidth()/2, GetScreenHeight()/2};
        default:
            return {0, 0};
    }
}

Rectangle Character::getCollisionRect() {
    return TextureRectFromCentre(getFront(), getPosAtLoc(getCurrentLoc()), 0.7f);
}

int Character::getCurrentEvent() {
    return choices.size();
}