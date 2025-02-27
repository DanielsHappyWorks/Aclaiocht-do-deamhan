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
            NarrativeSceneFactory::GetInstance()->getGymEvents()
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/sentra.png",
            "assets/images/locations/gym_indoor.png",
            "Sentra",
            "Item Shop",
            {70, 260},
            {}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/supperwacks.png",
            "assets/images/locations/gym_indoor.png",
            "Supperwacks",
            "Restaurant",
            {180, -30},
            {}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/pub.png",
            "assets/images/locations/gym_indoor.png",
            "Paddys Pub",
            "Pub",
            {385, 320},
            {}
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