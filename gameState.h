#pragma once
#include "raylib.h"
#include "enums.h"

class GameState {
    protected:
        GameState();
        ~GameState();
        static GameState* state;

        int day = 0;
        Time currentTime = DAY;
    public:
    GameState(GameState &other) = delete;
        void operator=(const GameState &) = delete;
        static GameState *GetInstance();

        int getDay();
        int getTime();
        void incrementTime(Time time);
};