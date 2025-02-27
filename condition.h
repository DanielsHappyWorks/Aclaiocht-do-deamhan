#pragma once
#include <string>

class Condition {
    public:
        virtual bool isMet() = 0;
};

class LocationCondition : public Condition {
    public:
        LocationCondition(std::string location);
        bool isMet();
};