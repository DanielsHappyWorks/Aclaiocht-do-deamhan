#pragma once
#include <vector>
#include "raylib.h"
#include "narrativeScene.h"

class NarrativeSceneFactory {
    protected:
        NarrativeSceneFactory();
        ~NarrativeSceneFactory();
        static NarrativeSceneFactory* factory;

        std::vector<NarrativeScene*> playerEvents;
        std::vector<NarrativeScene*> gymEvents;
        std::vector<NarrativeScene*> bansheeEvents;
        std::vector<NarrativeScene*> pookaEvents;
        std::vector<NarrativeScene*> dullahanEvents;
    public:
        NarrativeSceneFactory(NarrativeSceneFactory &other) = delete;
        void operator=(const NarrativeSceneFactory &) = delete;
        static NarrativeSceneFactory *GetInstance();

        std::vector<NarrativeScene*> getPlayerEvents();
        std::vector<NarrativeScene*> getGymEvents();
        std::vector<NarrativeScene*> getBansheeEvents();
        std::vector<NarrativeScene*> getPookaEvents();
        std::vector<NarrativeScene*> getDullahanEvents();
};