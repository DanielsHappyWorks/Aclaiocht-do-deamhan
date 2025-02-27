#pragma once
#include <string>
#include "raylib.h"

class Location {
    protected:
        std::string name;
        std::string type;
        Vector2 overworldLocation;

        Texture2D building;
        Texture2D background;
    public:
        Location(std::string building, std::string background, std::string name, std::string type, Vector2 overworldLocation);
        ~Location();
        void drawBuilding();
        void drawInterior();

        std::string getName();
        std::string getType();
};