#include "location.h"
#include "sceneManager.h"


Location::Location(std::string building, std::string background, std::string name, std::string type, Vector2 overworldLocation, Rectangle exit, std::vector<NarrativeScene*> events, Vector2 playerStart) {
    this->name = name;
    this->type = type;
    this->overworldLocation = overworldLocation;

    this->background = LoadTexture(background.c_str());
    this->building = LoadTexture(building.c_str());
    this->exit = exit;
    this->events = events;
    this->currentEvent = 0;
    this->playerStart = playerStart; 
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

Rectangle Location::getExit() {
    return exit;
}

Vector2 Location::getPlayerStart() {
    return playerStart;
}

Rectangle Location::getBuildingRect() {
    float buffer = 20.0f;
    return {overworldLocation.x + buffer, overworldLocation.y + buffer, building.width - buffer*2, building.height - buffer*2};
}

void Location::playAnyForcedEvents() {
    if (events.size() <= currentEvent) {
        return;
    }

    if (events[currentEvent]->isForced()) {
        SceneManager::GetInstance()->setSceneOverlay(events[currentEvent]);
        currentEvent++;
    }
}