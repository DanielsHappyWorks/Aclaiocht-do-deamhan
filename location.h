#pragma once
#include <string>
#include <vector>
#include "raylib.h"
#include "narrativeScene.h"

class Location {
    protected:
        std::string name;
        LocEnum type;
        Vector2 overworldLocation;
        std::vector<NarrativeScene*> events;
        Rectangle exit;
        int currentEvent;
        Vector2 playerStart;

        Texture2D building;
        Texture2D background;
    public:
        Location(std::string building, std::string background, std::string name, LocEnum type, Vector2 overworldLocation, Rectangle exit, std::vector<NarrativeScene*> events, Vector2 playerStart);
        ~Location();
        void drawBuilding();
        void drawInterior();

        std::string getName();
        LocEnum getType();
        Rectangle getExit();
        Vector2 getPlayerStart();
        Rectangle getBuildingRect();
        void playAnyForcedEvents();
};