#pragma once
#include <string>
#include <vector>
#include "raylib.h"
#include "narrativeScene.h"

class Location {
    protected:
        std::string name;
        std::string type;
        Vector2 overworldLocation;
        std::vector<NarrativeScene*> events;
        Rectangle exit;
        int currentEvent;

        Texture2D building;
        Texture2D background;
    public:
        Location(std::string building, std::string background, std::string name, std::string type, Vector2 overworldLocation, std::vector<NarrativeScene*> events);
        ~Location();
        void drawBuilding();
        void drawInterior();

        std::string getName();
        std::string getType();
        Rectangle getExit();
        Rectangle getBuildingRect();
        void playAnyForcedEvents();
};