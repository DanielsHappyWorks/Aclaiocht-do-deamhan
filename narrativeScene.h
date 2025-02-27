#pragma once
#include "scene.h"
#include "raylib.h"
#include "condition.h"
#include "narrativeNode.h"
#include <vector>
#include <string>

class NarrativeScene : public Scene {
    private:
        std::vector<NarrativeNode*> narrativeElements; 
        Condition* condition;
        bool forced;
        bool done;
        int currentElement;
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
};