#pragma once
#include <string>
#include "enums.h"
#include "character.h"
#include <vector>

class Condition {
    public:
        virtual bool isMet() = 0;
};

class CharacterAtLocationCondition : public Condition {
    private:
        Character* character;
        LocEnum location;
    public:
        CharacterAtLocationCondition(Character* character, LocEnum location);
        bool isMet();
};

class MetCharacterCondition : public Condition {
    private:
        Character* character;
        CharDialogChoices choice;
        int index;
    public:
        MetCharacterCondition(Character* character, int index, CharDialogChoices choice);
        bool isMet();
};

class CharacterEventsCompltededCondition : public Condition {
    private:
        std::vector<Character*> characters;
    public:
        CharacterEventsCompltededCondition(std::vector<Character*> character);
        bool isMet();
};