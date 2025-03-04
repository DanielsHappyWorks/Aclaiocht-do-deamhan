#include "character.h"

Character::Character(std::string name, CharEnum type, std::vector<LocEnum> dayLocations, std::vector<LocEnum> nightLocations, std::string front, std::string side) {
    this->name = name;
    this->type = type;
    this->dayLocations = dayLocations;
    this->nightLocations = nightLocations;
    this->front = LoadTexture(front.c_str());
    this->side = LoadTexture(side.c_str());
    this->choices = {};
    this->friendship = 0;
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
LocEnum Character::getCurrentLoc() {
    //TODO get day/night cycle!
    return dayLocations[0];
}

CharDialogChoices Character::getChoice(int index) {
    if (choices.size() <= index || index < 0) {
        return UNKNOWN;
    }

    return choices[index];
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

Rectangle Character::getCollisionRect(float scale) {
    return {getPosAtLoc(getCurrentLoc()).x, getPosAtLoc(getCurrentLoc()).y, (float)front.width * scale, (float)front.height * scale};
}

int Character::getCurrentEvent() {
    return choices.size();
}