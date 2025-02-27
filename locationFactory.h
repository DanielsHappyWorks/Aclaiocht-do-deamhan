#pragma once
#include <list>
#include "raylib.h"
#include "location.h"

class LocationFactory {
    protected:
        LocationFactory();
        ~LocationFactory();
        static LocationFactory* locationFactory;

        std::list<Location*> locations;
    public:
        LocationFactory(LocationFactory &other) = delete;
        void operator=(const LocationFactory &) = delete;
        static LocationFactory *GetInstance();

        std::list<Location*> getLocations();
        Location* getByType(std::string type);
};