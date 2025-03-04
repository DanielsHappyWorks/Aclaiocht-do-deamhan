#pragma once
#include <string>
#include <vector>
#include "soundManager.h"
#include "character.h"

enum NodeType {
    TEXT_NODE,
    MOOD_NODE,
    CHOICE_NODE,
    ADD_CHARACTER_NODE,
    REMOVE_CHARACTER_NODE,
    ADD_BACKGROUND_NODE,
    REMOVE_BACKGROUND_NODE
};

class NarrativeNode {
    public:
        virtual bool isDone() = 0;
        virtual void draw() = 0;
        virtual NodeType getType() = 0;
};

class TextNode : public NarrativeNode {
    private:
        Character* character;
        std::string text;
        Color color;

    public:
        TextNode(Character* character, std::string text, Color color);
        bool isDone();
        void draw();
        NodeType getType();
};

class MoodNode : public NarrativeNode {
    private:
        Song song;
    public:
        MoodNode(Song song);
        bool isDone();
        void draw();
        NodeType getType();
};

class ChoiceNode : public NarrativeNode {
    private:
        std::string question;
        std::string goodPrompt;
        std::vector<NarrativeNode*> goodDialog;
        std::string badPrompt;
        std::vector<NarrativeNode*> badDialog;

        bool selected;
        bool done;
    public:
        ChoiceNode(std::string question, std::string goodPrompt, std::vector<NarrativeNode*> goodDialog, std::string badPrompt, std::vector<NarrativeNode*> badDialog);
        bool isDone();
        void draw();
        NodeType getType();
        std::vector<NarrativeNode*> getChosenDialog();
}; 

class AddCharacterNode : public NarrativeNode {
    private:
        Character* character;
    public:
        AddCharacterNode(Character* character);
        bool isDone();
        void draw();
        NodeType getType();
        Character* getCharacter();

};

class RemoveCharacterNode : public NarrativeNode {
    private:
        Character* character;
    public:
        RemoveCharacterNode(Character* character);
        bool isDone();
        void draw();
        NodeType getType();
        Character* getCharacter();
};

class AddBackgroundNode : public NarrativeNode {
    private:
        Color color;
    public:
        AddBackgroundNode(Color color);
        bool isDone();
        void draw();
        NodeType getType();
        Color getColor();
};

class RemoveBackgroundNode : public NarrativeNode {
    public:
        RemoveBackgroundNode();
        bool isDone();
        void draw();
        NodeType getType();
};