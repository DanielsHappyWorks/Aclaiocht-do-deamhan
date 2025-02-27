#include "location.h"


Location::Location(std::string building, std::string background, std::string name, std::string type, Vector2 overworldLocation) {
    this->name = name;
    this->type = type;
    this->overworldLocation = overworldLocation;

    this->background = LoadTexture(background.c_str());
    this->building = LoadTexture(building.c_str());
}

Location::~Location() {
    UnloadTexture(building);
    UnloadTexture(background);
}

void Location::drawBuilding() {
    DrawTextureEx(building, overworldLocation, 0.0f, 1.0f, WHITE);
}

void Location::drawInterior() {
    DrawTextureEx(background, {0, 0}, 0.0f, 1.0f, WHITE);
}

std::string Location::getName() {
    return name;
}

std::string Location::getType() {
    return type;
}