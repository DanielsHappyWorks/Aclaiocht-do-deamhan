#include "narrativeSceneFactory.h"
#include "condition.h"
#include "narrativeNode.h"

NarrativeSceneFactory* NarrativeSceneFactory::factory = nullptr;

NarrativeSceneFactory *NarrativeSceneFactory::GetInstance()
{
    if(factory==nullptr){
        factory = new NarrativeSceneFactory();
    }
    return factory;
}

NarrativeSceneFactory::NarrativeSceneFactory() {
    playerEvents = {};

    gymEvents = {};
    gymEvents.push_back(new NarrativeScene({
        //TODO string replacemensts
        //TODO pass the character ref????
        new TextNode("PLAYER", "Finally arrived. Uncle Colin really pulled through for me here.", GRAY),
        new TextNode("PLAYER", "Not sure I could have landed this gig without him.", GRAY),
        new MoodNode(MUSIC_SHINNANIGANS),
        new TextNode("ST. PADDY", "Ahh you finally made it. The name is Paddy.", BLACK),
        new TextNode("ST. PADDY", "I'm the manager of this here joint. Tír na Síoga we call it.", BLACK),
        new TextNode("PLAYER", "I'm {{NAME}}, thank you for taking me on on such short notice.", BLACK)
    }, new LocationCondition("Gym"), true));


    bansheeEvents = {};

    pookaEvents = {};

    dullahanEvents = {};
}

NarrativeSceneFactory::~NarrativeSceneFactory() {

}

std::vector<NarrativeScene*> NarrativeSceneFactory::getPlayerEvents() {
    return playerEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getGymEvents() {
    return gymEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getBansheeEvents() {
    return bansheeEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getPookaEvents() {
    return pookaEvents;
}

std::vector<NarrativeScene*> NarrativeSceneFactory::getDullahanEvents() {
    return dullahanEvents;
}