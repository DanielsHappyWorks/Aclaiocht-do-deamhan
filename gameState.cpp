#include "gameState.h"

GameState* GameState::state = nullptr;

GameState *GameState::GetInstance()
{
    if(state==nullptr){
        state = new GameState();
    }
    return state;
}

GameState::GameState() {
}

GameState::~GameState() {
}

int GameState::getDay() {
    return day;
}

int GameState::getTime() {
    return currentTime;
}

void GameState::incrementTime(Time time) {
    if (time == FULL_DAY || (time == HALF_DAY && currentTime == NIGHT)) {
        day++;
        currentTime = DAY;
    } if (time == HALF_DAY && currentTime == DAY) {
        currentTime = NIGHT;
    }
}