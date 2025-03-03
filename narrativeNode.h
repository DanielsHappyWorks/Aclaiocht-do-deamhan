#pragma once
#include <string>
#include <vector>
#include "soundManager.h"
#include "character.h"

class NarrativeNode {
    public:
        virtual bool isDone() = 0;
        virtual void draw() = 0;
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
};

class MoodNode : public NarrativeNode {
    private:
        Song song;
    public:
        MoodNode(Song song);
        bool isDone();
        void draw();
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
}; 