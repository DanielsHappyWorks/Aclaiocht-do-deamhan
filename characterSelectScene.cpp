#include "characterSelectScene.h"
#include "raygui.h"
#include "player.h"

CharacterSelectScene::CharacterSelectScene() {
    maleBody = LoadTexture("assets/images/characters/mc/player_front_male.png");
    femaleBody = LoadTexture("assets/images/characters/mc/player_front_female.png");
}

CharacterSelectScene::~CharacterSelectScene() {
    UnloadTexture(maleBody);
    UnloadTexture(femaleBody);
}

void CharacterSelectScene::update() {
    //TODO update player
    //TODO notify game of scene completion
}

void CharacterSelectScene::draw() {

    if (!selectedGender) DrawRectangle(GetScreenWidth()/3 - maleBody.width/2 - 25, 85, maleBody.width + 50, maleBody.height + 30, LIGHTGRAY);
    DrawTextureEx(maleBody, (Vector2){GetScreenWidth()/3 - maleBody.width/2, 100}, 0.0f, 1.0f, WHITE);

    if (selectedGender) DrawRectangle(GetScreenWidth()/3*2 - femaleBody.width/2 - 25, 85, femaleBody.width + 50, femaleBody.height + 30, LIGHTGRAY);
    DrawTextureEx(femaleBody, (Vector2){GetScreenWidth()/3*2 - femaleBody.width/2, 100}, 0.0f, 1.0f, WHITE);

    if (GuiToggleSlider((Rectangle){ GetScreenWidth()/2 - 60, 330, 120, 30 }, "Male;Female", &toggleSliderActive) == true) selectedGender = !selectedGender;

    //GuiTextBox does not respect allignment for cursor when editing so lets left allign it while this happens
    textBoxEditMode == true ? GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_LEFT) : GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
    if (GuiTextBox((Rectangle){ GetScreenWidth()/2 - 60, 370, 120, 30 }, name, 25, textBoxEditMode)) textBoxEditMode = !textBoxEditMode;

    if (GuiButton((Rectangle){ GetScreenWidth()/2 - 60, 410, 120, 30 }, "Play Game")) characterCompleted = true;
}

bool CharacterSelectScene::isDone() {
    Player::GetInstance()->setDetails(selectedGender, name);
    return characterCompleted;
}