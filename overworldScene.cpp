#include "overworldScene.h"
#include "player.h"
#include "inputManager.h"
#include "raymath.h"
#include <string>

OverworldScene::OverworldScene() {
    playerPos = {406, 218};
    playerSpeed = 160;
    playerScale = 0.35f;

    background = LoadTexture("assets/images/locations/map.png");
    gym = LoadTexture("assets/images/locations/gym.png");
    sentra = LoadTexture("assets/images/locations/sentra.png");
    supperwacks = LoadTexture("assets/images/locations/supperwacks.png");
    pub = LoadTexture("assets/images/locations/pub.png");
}

OverworldScene::~OverworldScene() {
    UnloadTexture(background);
    UnloadTexture(gym);
    UnloadTexture(sentra);
    UnloadTexture(supperwacks);
    UnloadTexture(pub);
}

void OverworldScene::update() {
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
}

void OverworldScene::draw() {
    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(gym, (Vector2){550, 20}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(sentra, (Vector2){70, 260}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(supperwacks, (Vector2){180, -30}, 0.0f, 1.0f, WHITE);
    DrawTextureEx(pub, (Vector2){385, 320}, 0.0f, 1.0f, WHITE);
 
    DrawTextureEx(Player::GetInstance()->getCurrentSprite(), playerPos, 0.0f, playerScale, WHITE);
}

bool OverworldScene::isDone() {
    return false;
}