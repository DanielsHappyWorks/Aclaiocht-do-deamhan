#include "narrativeNode.h"
#include "raylib.h"
#include "raygui.h"
#include "inputManager.h"
#include "fontManager.h"
#include "player.h"

void drawDialogBox(std::string character, std::string text, Color color) {
    float padding = 50.0f;
    DrawRectangle(padding, (float) GetScreenHeight()/3*2, (float) GetScreenWidth() - padding*2, (float) GetScreenHeight() / 3 - padding, {255,255,255,200});

    DrawTextEx(FontManager::GetInstance()->getFont(), character.c_str(), {padding + 10, (float)GetScreenHeight()/3*2-20}, 45, FontManager::GetInstance()->getSpacing(), DARKGREEN);
    DrawTextEx(FontManager::GetInstance()->getFont(), text.c_str(), {padding + 30, (float)GetScreenHeight()/3*2 + 50}, 18, FontManager::GetInstance()->getSpacing(), color);
}

TextNode::TextNode(Character* character, std::string text, Color color) {
    this->character = character;
    this->text = text;
    this->color = color;
}

bool TextNode::isDone() {
    return (InputManager::GetInstance()->isInteracting());
}

void TextNode::draw() {
    if (text.find("{{NAME}}") != std::string::npos) {
        text = text.replace(text.find("{{NAME}}"), 8, Player::GetInstance()->getCharacter()->getName());
    }
    drawDialogBox(character->getName(), text, color);
}

MoodNode::MoodNode(Song song) {
    this->song = song;
}

bool MoodNode::isDone() {
    SoundManager::GetInstance()->playMusic(song);
    return true;
}
void MoodNode::draw() { }

ChoiceNode::ChoiceNode(std::string question, std::string goodPrompt, std::vector<NarrativeNode*> goodDialog, std::string badPrompt, std::vector<NarrativeNode*> badDialog) {
    this->question = question;
    this->goodPrompt = goodPrompt;
    this->goodDialog = goodDialog;
    this->badPrompt = badPrompt;
    this->badDialog = badDialog;
}
bool ChoiceNode::isDone() {
    return done;
}
void ChoiceNode::draw() {
    drawDialogBox("PLAYER", question, DARKGRAY);
}