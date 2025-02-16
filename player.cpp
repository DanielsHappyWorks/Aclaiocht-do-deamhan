#include "player.h"

Player* Player::player = nullptr;

Player *Player::GetInstance()
{
    if(player==nullptr){
        player = new Player();
    }
    return player;
}

Player::Player() {
    male_front = LoadTexture("assets/images/characters/mc/player_front_male.png");
    male_back = LoadTexture("assets/images/characters/mc/player_back_female.png");
    male_side = LoadTexture("assets/images/characters/mc/player_side_female.png");

    female_front = LoadTexture("assets/images/characters/mc/player_front_female.png");
    female_back = LoadTexture("assets/images/characters/mc/player_back_female.png");
    female_side = LoadTexture("assets/images/characters/mc/player_side_female.png");
}

Player::~Player() {
    UnloadTexture(male_front);
    UnloadTexture(male_back);
    UnloadTexture(male_side);

    UnloadTexture(female_front);
    UnloadTexture(female_back);
    UnloadTexture(female_side);
}

void Player::setDetails(bool gender, char* name) {
    this->gender = gender;
    this->name = name;
}

Texture2D Player::getCurrentSprite() {
    return gender ? female_front : male_front;
}