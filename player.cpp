#include "player.h"
#include "raymath.h"
#include "inputManager.h"
#include "rayxtend.h"
#include "soundManager.h"

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

    bop_speed = 0.05f;
    bop_factor = 1.0f;
    swagger = 0.0f;
    swagger_speed = 0.5f;

    character = new Character(name, PLAYER, SFX_DIALOG_MALE, {}, {}, "assets/images/characters/mc/player_front_male.png", "assets/images/characters/mc/player_side_male.png");
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

    if (gender) {
        character = new Character(name, PLAYER, SFX_DIALOG_FEMALE, {}, {}, "assets/images/characters/mc/player_front_female.png", "assets/images/characters/mc/player_side_female.png");
    } else {
        character = new Character(name, PLAYER, SFX_DIALOG_MALE, {}, {}, "assets/images/characters/mc/player_front_male.png", "assets/images/characters/mc/player_side_male.png");
    }
}

Texture2D Player::getCurrentSprite() {
    return currentSprite;
}

Vector2 Player::move(Vector2 playerPos, float playerSpeed, float playerScale) {
    if (bop_factor >= 1.0f || bop_factor <= 0.95f) {
        bop_speed *= -1;
    }

    bop_factor += GetFrameTime() * bop_speed;
    playerScale *= bop_factor;

    Vector2 movement = InputManager::GetInstance()->getMovement();
    movement = Vector2Scale(movement, playerSpeed);
    movement = Vector2Scale(movement, GetFrameTime());

    Vector2 nextPos = Vector2Add(playerPos, movement);

    Texture2D playerSprite = Player::GetInstance()->getCurrentSprite();

    if (nextPos.x - playerSprite.width/2 * playerScale <= 0) {
        nextPos.x = playerSprite.width/2 * playerScale;
    }

    if (nextPos.y <= 0 + playerSprite.height * playerScale) {
        nextPos.y = playerSprite.height * playerScale;
    }

    if (nextPos.x >= GetScreenWidth() - playerSprite.width/2 * playerScale) {
        nextPos.x = GetScreenWidth() - playerSprite.width/2 * playerScale;
    }

    if (nextPos.y >= GetScreenHeight()) {
        nextPos.y = GetScreenHeight();
    }

    Player::GetInstance()->animateCharacter(movement, playerPos, nextPos);

    if (nextPos.x != 0) {
        playerPos = nextPos;
    }

    return playerPos;
}

void Player::draw(Vector2 playerPos, float playerScale) {
    playerScale *= bop_factor;
    //DrawTextureEx(Player::GetInstance()->getCurrentSprite(), playerPos, swagger, playerScale, WHITE);
    //(Texture2D texture, Vector2 pos, Vector2 pivotPoint, float scale, float rotation, Color color)
    Vector2 pivotPoint = {Player::GetInstance()->getCurrentSprite().width/2*playerScale, Player::GetInstance()->getCurrentSprite().height*playerScale};
    DrawTextureFromPoint(Player::GetInstance()->getCurrentSprite(), playerPos, pivotPoint, playerScale, swagger, WHITE);
}

void Player::animateCharacter(Vector2 movement, Vector2 currentPos, Vector2 nextPos) {
    if (Vector2Equals(currentPos, nextPos)) {
        //idle
        SoundManager::GetInstance()->stopSound(SFX_WALK);
        currentSprite = gender ? female_front : male_front;
        swagger = 0.0f;
        return;
    }

    if (!SoundManager::GetInstance()->isPlaying(SFX_WALK)) {
        SoundManager::GetInstance()->playSound(SFX_WALK);
    }

    if (swagger >= 5.0f || swagger <= -5.0f) {
        swagger_speed *= -1;
    }

    swagger += swagger_speed;

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
    return {playerPos.x - currentSprite.width/2 * playerScale, playerPos.y - currentSprite.height * playerScale, currentSprite.width * playerScale, currentSprite.height * playerScale};
}

Character* Player::getCharacter() {
    return character;
}