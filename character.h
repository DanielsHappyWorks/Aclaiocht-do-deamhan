#pragma once
#include <string>
#include <vector>
#include "raylib.h"
#include "enums.h"

class Character {
    protected:
        std::string name;
        CharEnum type;
        std::vector<LocEnum> dayLocations;
        std::vector<LocEnum> nightLocations;
        std::vector<CharDialogChoices> choices;
        int friendship;

        Texture2D front;
        Texture2D side;

    public:
        Character(std::string name, CharEnum type, std::vector<LocEnum> dayLocations, std::vector<LocEnum> nightLocations, std::string front, std::string side);
        ~Character();

        Texture2D getFront();
        Texture2D getSide();

        std::string getName();
        CharEnum getType();
        LocEnum getCurrentLoc();
        CharDialogChoices getChoice(int index);
        int getFriendship();
};