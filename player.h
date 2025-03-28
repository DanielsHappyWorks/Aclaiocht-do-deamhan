#pragma once
#include <string>
#include "raylib.h"
#include "character.h"

class Player {
    protected:
        Player();
        ~Player();
        static Player* player;

        bool gender = false;
        std::string name = "Ailbhe";

        Texture2D male_front;
        Texture2D male_back;
        Texture2D male_side_l;
        Texture2D male_side_r;
    
        Texture2D female_front;
        Texture2D female_back;
        Texture2D female_side_l;
        Texture2D female_side_r;

        Texture2D currentSprite;

        Character* character;

        float bop_factor;
        float bop_speed;
        float swagger;
        float swagger_speed;
    public:
        Player(Player &other) = delete;
        void operator=(const Player &) = delete;
        static Player *GetInstance();

        Texture2D getCurrentSprite();
        void setDetails(bool gender, char* name);
        void animateCharacter(Vector2 movement, Vector2 currentPos, Vector2 nextPos);
        Vector2 move(Vector2 playerPos, float playerSpeed, float playerScale);
        void draw(Vector2 playerPos, float playerScale);
        Rectangle getCollisionRect(Vector2 playerPos, float playerScale);
        Character* getCharacter();
};