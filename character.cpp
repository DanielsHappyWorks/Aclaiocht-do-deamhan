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

