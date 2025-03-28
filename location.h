#pragma once
#include <string>
#include <vector>
#include "raylib.h"
#include "narrativeScene.h"

class InteriorItem {
    private:
        Vector2 position;
        Texture2D texture;
        float scale;
    public:
        InteriorItem(Vector2 position, std::string texture, float scale);
        ~InteriorItem();
        void draw();
        Rectangle getRect();
};

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
        Texture2D eventIcon;
        std::vector<InteriorItem*> interiors;
    public:
        Location(std::string building, std::string background, std::string name, LocEnum type, Vector2 overworldLocation, Rectangle exit, std::vector<NarrativeScene*> events, Vector2 playerStart, std::vector<InteriorItem*> interiors);
        ~Location();
        void drawBuilding();
        void drawInterior();

        std::string getName();
        LocEnum getType();
        Rectangle getExit();
        Vector2 getPlayerStart();
        Rectangle getBuildingRect();
        void playAnyForcedEvents();
        std::vector<InteriorItem*> getInteriors();
};