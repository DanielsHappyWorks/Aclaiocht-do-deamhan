#pragma once
#include <string>
#include <vector>
#include "rayxtend.h"
#include "enums.h"
#include "soundManager.h"

class Character {
    protected:
        std::string name;
        CharEnum type;
        SFX sound;
        std::vector<LocEnum> dayLocations;
        std::vector<LocEnum> nightLocations;
        std::vector<CharDialogChoices> choices;
        int friendship;
        Vector2 posAtLoc;

        Texture2D front;
        Texture2D side;

    public:
        Character(std::string name, CharEnum type, SFX sound, std::vector<LocEnum> dayLocations, std::vector<LocEnum> nightLocations, std::string front, std::string side, Vector2 posAtLoc);
        ~Character();

        Texture2D getFront();
        Texture2D getSide();

        std::string getName();
        CharEnum getType();
        SFX getSound();
        virtual LocEnum getCurrentLoc();
        void drawAtLoc();
        CharDialogChoices getChoice(int index);
        void addChoice(CharDialogChoices choice);
        int getFriendship();

        Vector2 getPosAtLoc(LocEnum loc);
        Rectangle getCollisionRect();

        int getCurrentEvent();
};

class PlayerCharacter : public Character {
    public:
        PlayerCharacter(std::string name, CharEnum type, SFX sound, std::string front, std::string side);
        LocEnum getCurrentLoc();
};