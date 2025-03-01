#include "narrativeScene.h"

NarrativeScene::NarrativeScene(std::vector<NarrativeNode*> narrativeElements) {
    NarrativeScene(narrativeElements, nullptr);
}

NarrativeScene::NarrativeScene(std::vector<NarrativeNode*> narrativeElements, Condition* condition) {
    NarrativeScene(narrativeElements, condition, false);
}

NarrativeScene::NarrativeScene(std::vector<NarrativeNode*> narrativeElements, bool forced) {
    NarrativeScene(narrativeElements, nullptr, forced);
}

NarrativeScene::NarrativeScene(std::vector<NarrativeNode*> narrativeElements, Condition* condition, bool forced) {
    this->narrativeElements = narrativeElements;
    this->condition = condition;
    this->forced = forced;
    this->done = false;
    this->currentElement = 0;
}

NarrativeScene::~NarrativeScene() {

}

void NarrativeScene::update() {
    if (narrativeElements.size() <= currentElement || done) {
        done = true;
        return;
    }

    if (narrativeElements[currentElement]->isDone()) {
        currentElement++;
    }
}

void NarrativeScene::draw() {
    if (narrativeElements.size() <= currentElement || done) {
        return;
    }

    narrativeElements[currentElement]->draw();
}

bool NarrativeScene::isDone() {
    if (done) {
        SoundManager::GetInstance()->playMusic(MUSIC_DAY);
    }

    return done;
}

void NarrativeScene::debug() {

}

bool NarrativeScene::isForced() {
    return forced;
}

bool NarrativeScene::isReady() {
    if (condition == nullptr) {
        return true;
    }

    return condition->isMet();
}