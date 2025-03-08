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
    REMOVE_BACKGROUND_NODE,
    PASS_TIME_NODE
};

enum TextNodeType {
    TEXT_MONOLOGUE,
    TEXT_DIALOGUE
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
        TextNodeType type;
        bool dialog = false;
        int dialogCounter = 0;

    public:
        TextNode(Character* character, std::string text, TextNodeType type);
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
        Character* character;
        std::string question;
        std::string goodPrompt;
        std::vector<NarrativeNode*> goodDialog;
        std::string badPrompt;
        std::vector<NarrativeNode*> badDialog;

        bool selected;
        bool done;
    public:
        ChoiceNode(Character* character, std::string question, std::string goodPrompt, std::vector<NarrativeNode*> goodDialog, std::string badPrompt, std::vector<NarrativeNode*> badDialog);
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

enum Time {
    FULL_DAY,
    HALF_DAY
};

class PassTimeNode : public NarrativeNode {
    private:
        Time time;
    public:
        PassTimeNode(Time time);
        bool isDone();
        void draw();
        NodeType getType();
};