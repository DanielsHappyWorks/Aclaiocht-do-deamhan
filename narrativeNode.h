#pragma once
#include <string>

class NarrativeNode {
    public:
        virtual bool isDone() = 0;
        virtual void draw() = 0;
};

class TextNode : public NarrativeNode {
    private:
        std::string character;
        std::string text;

    public:
        TextNode(std::string character, std::string text);
        bool isDone();
        void draw();
};