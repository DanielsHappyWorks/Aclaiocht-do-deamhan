#pragma once
#include <list>
#include "raylib.h"
#include "character.h"
#include "narrativeScene.h"

class CharacterFactory {
    protected:
        CharacterFactory();
        ~CharacterFactory();
        static CharacterFactory* factory;

        Character* banshee;
        Character* paddy;
        Character* pooka;
        Character* dullahan;
    public:
        CharacterFactory(CharacterFactory &other) = delete;
        void operator=(const CharacterFactory &) = delete;
        static CharacterFactory *GetInstance();

        std::list<Character*> getCharacters();
        Character* getCharacter(CharEnum charEnum);
        std::vector<Character*> getCharactersAtLoc(LocEnum loc);

        bool isNarrativeSceneReady(CharEnum charEnum);
        NarrativeScene* getNarrativeScene(CharEnum charEnum);
};