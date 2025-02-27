#include "player.h"
#include "raymath.h"
#include "inputManager.h"

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
    male_back = LoadTexture("assets/images/characters/mc/player_back_male.png");
    male_side_l = LoadTexture("assets/images/characters/mc/player_side_male.png");
    male_side_r = LoadTexture("assets/images/characters/mc/player_side_male_l.png");

    female_front = LoadTexture("assets/images/characters/mc/player_front_female.png");
    female_back = LoadTexture("assets/images/characters/mc/player_back_female.png");
    female_side_l = LoadTexture("assets/images/characters/mc/player_side_female.png");
    female_side_r = LoadTexture("assets/images/characters/mc/player_side_female_l.png");

    currentSprite = male_front;
}

Player::~Player() {
    UnloadTexture(male_front);
    UnloadTexture(male_back);
    UnloadTexture(male_side_l);
    UnloadTexture(male_side_r);

    UnloadTexture(female_front);
    UnloadTexture(female_back);
    UnloadTexture(female_side_l);
    UnloadTexture(female_side_r);
}

void Player::setDetails(bool gender, char* name) {
    this->currentSprite = gender ? female_front : male_front;
    this->gender = gender;
    this->name = name;
}

Texture2D Player::getCurrentSprite() {
    return currentSprite;
}

Vector2 Player::move(Vector2 playerPos, float playerSpeed, float playerScale) {
    Vector2 movement = InputManager::GetInstance()->getMovement();
    movement = Vector2Scale(movement, playerSpeed);
    movement = Vector2Scale(movement, GetFrameTime());

    Vector2 nextPos = Vector2Add(playerPos, movement);

    if (nextPos.x <= 0) {
        nextPos.x = 0;
    }

    if (nextPos.y <= 0) {
        nextPos.y = 0;
    }

    Texture2D playerSprite = Player::GetInstance()->getCurrentSprite();

    if (nextPos.x >= GetScreenWidth() - playerSprite.width * playerScale) {
        nextPos.x = GetScreenWidth() - playerSprite.width * playerScale;
    }

    if (nextPos.y >= GetScreenHeight() - playerSprite.height * playerScale) {
        nextPos.y = GetScreenHeight() - playerSprite.height * playerScale;
    }

    Player::GetInstance()->animateCharacter(movement, playerPos, nextPos);

    if (nextPos.x != 0) {
        playerPos = nextPos;
    }

    return playerPos;
}

void Player::draw(Vector2 playerPos, float playerScale) {
    DrawTextureEx(Player::GetInstance()->getCurrentSprite(), playerPos, 0.0f, playerScale, WHITE);
}

void Player::animateCharacter(Vector2 movement, Vector2 currentPos, Vector2 nextPos) {
    if (Vector2Equals(currentPos, nextPos)) {
        //idle
        currentSprite = gender ? female_front : male_front;
        return;
    }

    if (movement.y < 0.0f) {
        currentSprite = gender ? female_back : male_back;
    } else if (movement.y > 0) {
        currentSprite = gender ? female_front : male_front;
    } else if (movement.x < 0) {
        currentSprite = gender ? female_side_r : male_side_r;
    } else if (movement.x > 0) {
        currentSprite = gender ? female_side_l : male_side_l;
    }
}

Rectangle Player::getCollisionRect(Vector2 playerPos, float playerScale) {
    return {playerPos.x, playerPos.y, currentSprite.width * playerScale, currentSprite.height * playerScale};
}