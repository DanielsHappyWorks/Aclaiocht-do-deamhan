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
            GYM,
            {550, 20},
            {350, 500, 120, 100},
            NarrativeSceneFactory::GetInstance()->getGymEvents(),
            {415, 600},
            {new InteriorItem({30, 100}, "assets/images/locations/gym_bike.png", 0.7f),
            new InteriorItem({30, 200}, "assets/images/locations/gym_bike.png", 0.7f),
            new InteriorItem({600, 100}, "assets/images/locations/gym_thread.png", 0.7f),
            new InteriorItem({600, 250}, "assets/images/locations/gym_thread.png", 0.7f),
            new InteriorItem({200, 50}, "assets/images/locations/gym_weight_b.png", 0.7f),
            new InteriorItem({400, 50}, "assets/images/locations/gym_weight_b.png", 0.7f),
            new InteriorItem({30, 400}, "assets/images/locations/gym_weight.png", 0.7f),
            new InteriorItem({100, 400}, "assets/images/locations/gym_weight.png", 0.7f),
            new InteriorItem({30, 500}, "assets/images/locations/gym_weight.png", 0.7f),
            new InteriorItem({100, 500}, "assets/images/locations/gym_weight.png", 0.7f),
            new InteriorItem({600, 500}, "assets/images/locations/gym_weight_k.png", 0.6),
            new InteriorItem({670, 460}, "assets/images/locations/gym_weight_k.png", 0.6f),}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/sentra.png",
            "assets/images/locations/sentra_indoor.png",
            "Sentra",
            SHOP,
            {70, 260},
            {310, 490, 140, 110},
            {},
            {365, 600},
            {new InteriorItem({150, 100}, "assets/images/locations/sentra_shelf.png", 1.0f),
            new InteriorItem({150, 350}, "assets/images/locations/sentra_shelf.png", 1.0f),
            new InteriorItem({550, 100}, "assets/images/locations/sentra_shelf.png", 1.0f),
            new InteriorItem({550, 350}, "assets/images/locations/sentra_shelf.png", 1.0f),}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/supperwacks.png",
            "assets/images/locations/supperwacks_indoor.png",
            "Supperwacks",
            RESTAURANT,
            {180, -30},
            {680, 260, 120, 120},
            {},
            {750, 350},
            {new InteriorItem({170, 400}, "assets/images/locations/chair_a.png", 0.8f),
            new InteriorItem({150, 450}, "assets/images/locations/table_a.png", 1.0f),
            new InteriorItem({120, 450}, "assets/images/locations/chair_b.png", 0.8f),
            new InteriorItem({550, 100}, "assets/images/locations/table_a.png", 1.0f),
            new InteriorItem({470, 100}, "assets/images/locations/chair_a.png", 0.8f),
            new InteriorItem({650, 100}, "assets/images/locations/chair_a.png", 0.8f),
            new InteriorItem({550, 450}, "assets/images/locations/table_a.png", 1.0f),
            new InteriorItem({650, 450}, "assets/images/locations/chair_a.png", 0.8f),
            new InteriorItem({500, 450}, "assets/images/locations/chair_b.png", 0.8f),}
    ));

    locations.push_back(
        new Location(
            "assets/images/locations/pub.png",
            "assets/images/locations/pub_indoor.png",
            "Paddys Pub",
            PUB,
            {385, 320},
            {0, 280, 130, 130},
            {},
            {70, 370},
            {new InteriorItem({480, 105}, "assets/images/locations/pub_bar.png", 0.8f),
            new InteriorItem({210, 150}, "assets/images/locations/chair_a.png", 0.8f),
            new InteriorItem({200, 200}, "assets/images/locations/table_b.png", 1.0f),
            new InteriorItem({150, 200}, "assets/images/locations/chair_b.png", 0.8f),
            new InteriorItem({210, 350}, "assets/images/locations/chair_a.png", 0.8f),
            new InteriorItem({200, 400}, "assets/images/locations/table_b.png", 1.0f),
            new InteriorItem({150, 400}, "assets/images/locations/chair_b.png", 0.8f),
            new InteriorItem({510, 350}, "assets/images/locations/chair_a.png", 0.8f),
            new InteriorItem({500, 400}, "assets/images/locations/table_b.png", 1.0f),
            new InteriorItem({450, 400}, "assets/images/locations/chair_b.png", 0.8f),}
    ));
}

LocationFactory::~LocationFactory() {

}

std::list<Location*> LocationFactory::getLocations() {
    return locations;
}

Location* LocationFactory::getByType(LocEnum type) {
    for (Location* loc : locations) {
        if (loc->getType() == type) {
            return loc;
        }
    }

    return nullptr;
}