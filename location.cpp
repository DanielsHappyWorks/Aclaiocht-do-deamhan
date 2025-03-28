#include "location.h"
#include "sceneManager.h"
#include "characterFactory.h"

InteriorItem::InteriorItem(Vector2 position, std::string texture, float scale) {
    this->position = position;
    this->texture = LoadTexture(texture.c_str());
    this->scale = scale;
}

InteriorItem::~InteriorItem() {
    UnloadTexture(texture);
}

void InteriorItem::draw() {
    DrawTextureEx(texture, position, 0.0f, (float)scale, WHITE);
}

Rectangle InteriorItem::getRect() {
    return {position.x, position.y, texture.width*scale, texture.height*scale};
}

Location::Location(std::string building, std::string background, std::string name, LocEnum type, Vector2 overworldLocation, Rectangle exit, std::vector<NarrativeScene*> events, Vector2 playerStart, std::vector<InteriorItem*> interiors) {
    this->name = name;
    this->type = type;
    this->overworldLocation = overworldLocation;

    this->background = LoadTexture(background.c_str());
    this->building = LoadTexture(building.c_str());
    this->exit = exit;
    this->events = events;
    this->currentEvent = 0;
    this->playerStart = playerStart;
    this->interiors = interiors;

    eventIcon = LoadTexture("assets/images/icons/event.png");
}

Location::~Location() {
    UnloadTexture(building);
    UnloadTexture(background);
    UnloadTexture(eventIcon);
}

void Location::drawBuilding() {
    DrawTextureEx(building, overworldLocation, 0.0f, 1.0f, WHITE);
    std::vector<Character*> characters = CharacterFactory::GetInstance()->getCharactersAtLoc(getType());
    for (Character* character : characters) {
        if (CharacterFactory::GetInstance()->isCoreSceneReady(character->getType())) {
            Rectangle rect = getBuildingRect();
            DrawTextureFromCentre(eventIcon, {rect.x + rect.width - 10, rect.y + 30}, 0.6f, 0.0f, YELLOW);
        }
    }
}

void Location::drawInterior() {
    DrawTextureEx(background, {0, 0}, 0.0f, 1.0f, WHITE);
}

std::string Location::getName() {
    return name;
}

LocEnum Location::getType() {
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

    for (NarrativeScene* scene : events) {
        if (scene->isForced() && scene->isReady() && !scene->isDone()) {
            SceneManager::GetInstance()->setSceneOverlay(scene);
        }
    }
}

std::vector<InteriorItem*> Location::getInteriors() {
    return interiors;
}