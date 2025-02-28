#include "locationFactory.h"
#include "narrativeSceneFactory.h"

LocationFactory* LocationFactory::locationFactory = nullptr;

LocationFactory *LocationFactory::GetInstance()
{
    if(locationFactory==nullptr){
        locationFactory = new LocationFactory();
    }
    return locationFactory;
}

LocationFactory::LocationFactory() {
    locations = {};

    locations.push_back(
        new Location(
            "assets/images/locations/gym.png",
            "assets/images/locations/gym_indoor.png",
            "Tír na Sioga",
            "Gym",
            {550, 20},
            {350, 500, 120, 100},
            NarrativeSceneFactory::GetInstance()->getGymEvents(),
            {415, 600}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/sentra.png",
            "assets/images/locations/sentra_indoor.png",
            "Sentra",
            "Item Shop",
            {70, 260},
            {310, 490, 140, 110},
            {},
            {365, 600}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/supperwacks.png",
            "assets/images/locations/supperwacks_indoor.png",
            "Supperwacks",
            "Restaurant",
            {180, -30},
            {680, 260, 120, 120},
            {},
            {750, 350}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/pub.png",
            "assets/images/locations/pub_indoor.png",
            "Paddys Pub",
            "Pub",
            {385, 320},
            {0, 280, 130, 130},
            {},
            {70, 370}
    ));
}

LocationFactory::~LocationFactory() {

}

std::list<Location*> LocationFactory::getLocations() {
    return locations;
}

Location* LocationFactory::getByType(std::string type) {
    for (Location* loc : locations) {
        if (loc->getType() == type) {
            return loc;
        }
    }

    return nullptr;
}