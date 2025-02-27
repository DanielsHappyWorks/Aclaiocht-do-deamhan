#include "narrativeNode.h"
#include "raylib.h"
#include "inputManager.h"

TextNode::TextNode(std::string character, std::string text) {
    this->character = character;
    this->text = text;
}

bool TextNode::isDone() {
    return (InputManager::GetInstance()->isInteracting());
}

void TextNode::draw() {
    DrawText(character.c_str(), 10, 10, 30, BLACK);
    DrawText(text.c_str(), 10, 30, 30, BLACK);
}