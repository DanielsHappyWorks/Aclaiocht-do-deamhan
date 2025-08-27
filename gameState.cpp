#include "gameState.h"
#include "fontManager.h"
#include <string>
#include "constants.h"

GameState* GameState::state = nullptr;

GameState *GameState::GetInstance()
{
    if(state==nullptr){
        state = new GameState();
    }
    return state;
}

GameState::GameState() {
    dayNightIndicator = LoadTexture("assets/images/objects/day_time.png");
    arrow = LoadTexture("assets/images/icons/arrow.png");
}

GameState::~GameState() {
    UnloadTexture(dayNightIndicator);
    UnloadTexture(arrow);
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
    } else if (time == HALF_DAY && currentTime == DAY) {
        currentTime = NIGHT;
    }
}

void GameState::drawDayNight() {
    if (currentTime == NIGHT) {
        DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, Fade(DARKBLUE, 0.2f));
    }

    DrawTextureEx(dayNightIndicator, {0, 0}, 0.0f, 1.0f, WHITE);

    Vector2 arrowPos = {10, 10};
    float scale = 0.8f;
    Vector2 pivotPoint = {arrow.width/2*scale, arrow.height*scale};
    if (currentTime == NIGHT) {
        DrawTextureFromPoint(arrow, arrowPos, pivotPoint, scale, 150, WHITE);
    } else {
        DrawTextureFromPoint(arrow, arrowPos, pivotPoint, scale, 105, WHITE);
    }

    std::string days = "Day " + std::to_string(day);
    DrawTextEx(FontManager::GetInstance()->getFontHeaders(), days.c_str(), {10, 90}, 20, FontManager::GetInstance()->getSpacing(), DARKGREEN);
}