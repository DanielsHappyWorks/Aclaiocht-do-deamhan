#pragma once
#include "scene.h"
#include "rayxtend.h"
#include "condition.h"
#include "narrativeNode.h"
#include <vector>
#include <string>

class NarrativeScene : public SceneOverlay {
    private:
        std::vector<NarrativeNode*> narrativeElements; 
        Condition* condition;
        bool forced;
        bool done;
        bool doneAtLoc;
        int currentElement;
        std::vector<Character*> characters;
        Color color = {255,255,255,0};

        void addCharacter(Character* character);
        void removeCharacter(Character* character);
    public:
        NarrativeScene(std::vector<NarrativeNode*> narrativeElements);
        NarrativeScene(std::vector<NarrativeNode*> narrativeElements, Condition* condition);
        NarrativeScene(std::vector<NarrativeNode*> narrativeElements, bool forced);
        NarrativeScene(std::vector<NarrativeNode*> narrativeElements, Condition* condition, bool forced);
        ~NarrativeScene();
        void update();
        void draw();
        bool isDone();
        void debug();
        bool isForced();
        bool isReady();
        bool isDoneAtLoc();
};