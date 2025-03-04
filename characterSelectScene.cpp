#include "characterSelectScene.h"
#include "raygui.h"
#include "player.h"
#include "locationScene.h"
#include "locationFactory.h"
#include "sceneManager.h"
#include "inputManager.h"
#include "rayxtend.h"
#include "fontManager.h"

CharacterSelectScene::CharacterSelectScene()
{
    background = LoadTexture("assets/images/locations/char_sel.png");

    sun = LoadTexture("assets/images/objects/sun.png");
    sun_rotation = 0.0f;

    cloud_one = LoadTexture("assets/images/objects/cloud1.png");
    cloud_one_pos = {50, 50};
    cloud_one_scale = 0.5f;

    cloud_two = LoadTexture("assets/images/objects/cloud2.png");
    cloud_two_pos = {100, 150};
    cloud_two_scale = 0.4f;

    cloud_three = LoadTexture("assets/images/objects/cloud3.png");
    cloud_three_pos = {450, 100};
    cloud_three_scale = 0.3f;

    maleBody = LoadTexture("assets/images/characters/mc/player_front_male.png");
    femaleBody = LoadTexture("assets/images/characters/mc/player_front_female.png");
}

CharacterSelectScene::~CharacterSelectScene()
{
    UnloadTexture(maleBody);
    UnloadTexture(femaleBody);

    UnloadTexture(sun);
    UnloadTexture(cloud_one);
    UnloadTexture(cloud_two);
    UnloadTexture(cloud_three);
}

void CharacterSelectScene::update()
{
    if (InputManager::GetInstance()->isClickRect({(float)GetScreenWidth() / 3 - maleBody.width / 2, 100, (float)maleBody.width, (float)maleBody.height}))
    {
        toggleSliderActive = false;
        selectedGender = false;
    }
    else if (InputManager::GetInstance()->isClickRect({(float)GetScreenWidth() / 3 * 2 - femaleBody.width / 2, 100, (float)femaleBody.width, (float)femaleBody.height}))
    {
        toggleSliderActive = true;
        selectedGender = true;
    }

    sun_rotation += GetFrameTime() * 20.0f;
    cloud_one_pos.x += GetFrameTime() * 10.0f;
    cloud_two_pos.x += GetFrameTime() * 15.0f;
    cloud_three_pos.x += GetFrameTime() * 20.0f;

    if (cloud_one_pos.x - sun.width/2*cloud_one_scale >= GetScreenWidth()) cloud_one_pos.x = 0 - sun.width/2*cloud_one_scale;
    if (cloud_two_pos.x - sun.width/2*cloud_two_scale >= GetScreenWidth()) cloud_two_pos.x = 0 - sun.width/2*cloud_two_scale;
    if (cloud_three_pos.x - sun.width/2*cloud_three_scale >= GetScreenWidth()) cloud_three_pos.x = 0 - sun.width/2*cloud_three_scale;
}

void CharacterSelectScene::draw()
{
    DrawTextureEx(background, {0, 0}, 0.0f, 1.0f, WHITE);

    DrawTextureFromCentre(cloud_one, cloud_one_pos, cloud_one_scale, 0.0f, WHITE);
    DrawTextureFromCentre(cloud_two, cloud_two_pos, cloud_two_scale, 0.0f, WHITE);
    DrawTextureFromCentre(cloud_three, cloud_three_pos, cloud_three_scale, 0.0f, WHITE);

    if (!selectedGender)
        DrawTextureFromCentre(sun, {(float)GetScreenWidth() / 3, 200}, 0.4f, sun_rotation, WHITE);
    DrawTextureEx(maleBody, (Vector2){GetScreenWidth() / 3 - maleBody.width / 2, 140}, 0.0f, 1.0f, WHITE);

    if (selectedGender)
        DrawTextureFromCentre(sun, {(float)GetScreenWidth() / 3 * 2, 200}, 0.4f, sun_rotation, WHITE);
    DrawTextureEx(femaleBody, (Vector2){GetScreenWidth() / 3 * 2 - femaleBody.width / 2, 140}, 0.0f, 1.0f, WHITE);

    if (GuiToggleSlider((Rectangle){GetScreenWidth() / 2 - 60, 360, 120, 30}, "Male;Female", &toggleSliderActive) == true)
        selectedGender = !selectedGender;

    // GuiTextBox does not respect allignment for cursor when editing so lets left allign it while this happens
    textBoxEditMode == true ? GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_LEFT) : GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
    if (GuiTextBox((Rectangle){GetScreenWidth() / 2 - 60, 400, 120, 30}, name, 25, textBoxEditMode))
        textBoxEditMode = !textBoxEditMode;

    if (GuiButton((Rectangle){GetScreenWidth() / 2 - 60, 440, 120, 30}, "Play Game"))
        characterCompleted = true;

    DrawTextEx(FontManager::GetInstance()->getFont(), "Exercise your Demons!", {85, 35}, 60, FontManager::GetInstance()->getSpacing(), DARKGREEN);
}

bool CharacterSelectScene::isDone()
{
    if (characterCompleted)
    {
        Player::GetInstance()->setDetails(selectedGender, name);
        SceneManager::GetInstance()->setCurrentScene(new LocationScene(LocationFactory::GetInstance()->getByType(GYM)));
    }

    return characterCompleted;
}

void CharacterSelectScene::debug()
{
}

void CharacterSelectScene::drawSunAtPos(Vector2 pos)
{
    float sun_scale = 0.4f;
    Rectangle sun_rect = {0, 0, (float)sun.width, (float)sun.height};
    Rectangle sun_pos = {pos.x, pos.y, (float)sun.width * sun_scale, (float)sun.height * sun_scale};
    Vector2 sun_centre = {(float)sun.width * sun_scale / 2, (float)sun.height * sun_scale / 2};
    DrawTexturePro(sun, sun_rect, sun_pos, sun_centre, sun_rotation, WHITE);
}