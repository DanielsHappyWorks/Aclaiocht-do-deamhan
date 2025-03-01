#pragma once
#include <string>
#include "soundManager.h"

class NarrativeNode {
    public:
        virtual bool isDone() = 0;
        virtual void draw() = 0;
};

class TextNode : public NarrativeNode {
    private:
        std::string character;
        std::string text;
        Color color;

    public:
        TextNode(std::string character, std::string text, Color color);
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