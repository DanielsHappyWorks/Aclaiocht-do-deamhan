#include "narrativeNode.h"
#include "raylib.h"
#include "raygui.h"
#include "inputManager.h"
#include "fontManager.h"
#include "player.h"
#include "sceneManager.h"

void drawDialogBox(std::string character, std::string text, TextNodeType type)
{
    float padding = 50.0f;
    float textLen = MeasureTextEx(FontManager::GetInstance()->getFontHeaders(), character.c_str(), 45, FontManager::GetInstance()->getSpacing()).x + 20; 
    DrawRectangle(padding, (float)GetScreenHeight() / 3 * 2, (float)GetScreenWidth() - padding * 2, (float)GetScreenHeight() / 3 - padding, {255, 255, 255, 200});
    DrawRectangle(padding, (float)GetScreenHeight() / 3 * 2 - 20, textLen, 20, {255, 255, 255, 200});

    DrawTextEx(FontManager::GetInstance()->getFontHeaders(), character.c_str(), {padding + 10, (float)GetScreenHeight() / 3 * 2 - 20}, 45, FontManager::GetInstance()->getSpacing(), DARKGREEN);

    switch (type) {
        case TEXT_MONOLOGUE:
            DrawTextEx(FontManager::GetInstance()->getFontItal(), text.c_str(), {padding + 30, (float)GetScreenHeight() / 3 * 2 + 50}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
            break;
        case TEXT_DIALOGUE:
        default:
            DrawTextEx(FontManager::GetInstance()->getFont(), text.c_str(), {padding + 30, (float)GetScreenHeight() / 3 * 2 + 50}, 18, FontManager::GetInstance()->getSpacing(), BLACK);
    }
}

TextNode::TextNode(Character *character, std::string text, TextNodeType type)
{
    int maxLineLength = 56;
    if (text.length() > maxLineLength)
    {
        int lastSpace = text.find_last_of(" ", maxLineLength);
        text.replace(lastSpace, 1, "\n");
    }

    this->character = character;
    this->text = text; 
    this->type = type;
}

bool TextNode::isDone()
{
    bool isInteract = (InputManager::GetInstance()->isInteracting());

    if (isInteract && dialogCounter < text.length())
    {
        dialogCounter = text.length();
        return false;
    }

    if (isInteract)
    {
        SoundManager::GetInstance()->stopSound(character->getSound());
    }
    return isInteract;
}

void TextNode::draw()
{
    if (!dialog && TEXT_DIALOGUE == type)
    {
        SoundManager::GetInstance()->playSound(character->getSound());
        dialog = true;
    }

    if (text.find("{{NAME}}") != std::string::npos)
    {
        text = text.replace(text.find("{{NAME}}"), 8, Player::GetInstance()->getCharacter()->getName());
    }

    //get dialog from text by dialog counter
    std::string dialog = text.substr(0, dialogCounter);
    if (dialogCounter < text.length())
    {
        dialogCounter++;
    }

    drawDialogBox(character->getName(), dialog, type);
}

NodeType TextNode::getType()
{
    return TEXT_NODE;
}

MoodNode::MoodNode(Song song)
{
    this->song = song;
}

bool MoodNode::isDone()
{
    SoundManager::GetInstance()->playMusic(song);
    return true;
}
void MoodNode::draw() {}

NodeType MoodNode::getType()
{
    return MOOD_NODE;
}

ChoiceNode::ChoiceNode(Character* character, std::string question, std::string goodPrompt, std::vector<NarrativeNode *> goodDialog, std::string badPrompt, std::vector<NarrativeNode *> badDialog)
{
    this->character = character;
    this->question = question;
    this->goodPrompt = goodPrompt;
    this->goodDialog = goodDialog;
    this->badPrompt = badPrompt;
    this->badDialog = badDialog;
    this->selected = true;
    this->done = false;
}
bool ChoiceNode::isDone()
{
    return done;
}
void ChoiceNode::draw()
{
    drawDialogBox(Player::GetInstance()->getCharacter()->getName(), question, TEXT_DIALOGUE);

    float btnPadding = 80;

    //Hack to prevent instant click on buttons
    int disabledFrames = 30;
    if (frameCounter <= disabledFrames)
        frameCounter++;

    if (GuiButton({btnPadding, (float)GetScreenHeight() / 3 * 2 + 70, (float)GetScreenWidth() - btnPadding * 2, 34}, goodPrompt.c_str()) && frameCounter >= disabledFrames)
    {
        SoundManager::GetInstance()->playSound(SFX_CLICK);
        if (character != nullptr) {
            character->addChoice(GOOD);
        }
        selected = true;
        done = true;
    }

    if (GuiButton({btnPadding, (float)GetScreenHeight() / 3 * 2 + 110, (float)GetScreenWidth() - btnPadding * 2, 34}, badPrompt.c_str()) && frameCounter >= disabledFrames)
    {
        if (character != nullptr) {
            SoundManager::GetInstance()->playSound(SFX_ERROR);
            character->addChoice(BAD);
        } else {
            SoundManager::GetInstance()->playSound(SFX_CLICK);
        }
        selected = false;
        done = true;
    }
}

NodeType ChoiceNode::getType()
{
    return CHOICE_NODE;
}

std::vector<NarrativeNode *> ChoiceNode::getChosenDialog()
{
    if (selected)
    {
        return goodDialog;
    }
    else
    {
        return badDialog;
    }
}

AddCharacterNode::AddCharacterNode(Character *character)
{
    this->character = character;
}

bool AddCharacterNode::isDone()
{
    return true;
}

void AddCharacterNode::draw() {}

NodeType AddCharacterNode::getType()
{
    return ADD_CHARACTER_NODE;
}

Character *AddCharacterNode::getCharacter()
{
    return character;
}

RemoveCharacterNode::RemoveCharacterNode(Character *character)
{
    this->character = character;
}

bool RemoveCharacterNode::isDone()
{
    return true;
}

void RemoveCharacterNode::draw() {}

NodeType RemoveCharacterNode::getType()
{
    return REMOVE_CHARACTER_NODE;
}

Character *RemoveCharacterNode::getCharacter()
{
    return character;
}

AddBackgroundNode::AddBackgroundNode(Color color)
{
    this->color = color;
}

bool AddBackgroundNode::isDone()
{
    return true;
}

void AddBackgroundNode::draw() {}

Color AddBackgroundNode::getColor()
{
    return color;
}

NodeType AddBackgroundNode::getType()
{
    return ADD_BACKGROUND_NODE;
}

RemoveBackgroundNode::RemoveBackgroundNode() {}

bool RemoveBackgroundNode::isDone()
{
    return true;
}

void RemoveBackgroundNode::draw() {}

NodeType RemoveBackgroundNode::getType()
{
    return REMOVE_BACKGROUND_NODE;
}

PassTimeNode::PassTimeNode(Time time)
{
    this->time = time;
}

bool PassTimeNode::isDone()
{
    return true;
}

void PassTimeNode::draw() {}

NodeType PassTimeNode::getType()
{
    return PASS_TIME_NODE;
}

Time PassTimeNode::getTime()
{
    return time;
}

SceneChangeNode::SceneChangeNode(Scene *scene)
{
    this->scene = scene;
}

bool SceneChangeNode::isDone()
{
    SceneManager::GetInstance()->setCurrentScene(scene, true);
    return true;
}

void SceneChangeNode::draw() {}

NodeType SceneChangeNode::getType()
{
    return SCENE_CHANGE_NODE;
}

RandomNode::RandomNode(std::vector<NarrativeNode *> nodes)
{
    this->nodes = nodes;
}

bool RandomNode::isDone()
{
    return true;
}

void RandomNode::draw() {}

NodeType RandomNode::getType()
{
    return RANDOM_NODE;
}

NarrativeNode* RandomNode::getRandomNode()
{
    return nodes[rand() % nodes.size()];
}

ItemShopNode::ItemShopNode() {
    done = false;
}

bool ItemShopNode::isDone()
{
    return done;
}

void ItemShopNode::draw() {
    float hight = GetScreenHeight()/2 - 200;

    if (GuiWindowBox((Rectangle){GetScreenWidth()/2 - 200, hight, 400, 400}, "Item Shop")) {
        done = true;
    }

    //TODO add item shop items
    DrawTextEx(FontManager::GetInstance()->getFont(), "There are currently no items \nfor sale.", {(float)GetScreenWidth()/2 - 170, hight + 40}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);

    if (GuiButton((Rectangle){GetScreenWidth()/2 - 80, hight + 330, 160, 30}, "Exit")) {
        done = true;
    }
}

NodeType ItemShopNode::getType()
{
    return ITEM_SHOP_NODE;
}