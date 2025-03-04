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
    
    if(narrativeElements[currentElement]->getType() == ADD_CHARACTER_NODE) {
        addCharacter(((AddCharacterNode*)narrativeElements[currentElement])->getCharacter());
    } else if(narrativeElements[currentElement]->getType() == REMOVE_CHARACTER_NODE) {
        removeCharacter(((RemoveCharacterNode*)narrativeElements[currentElement])->getCharacter());
    } else if(narrativeElements[currentElement]->getType() == ADD_BACKGROUND_NODE) {
        color = ((AddBackgroundNode*)narrativeElements[currentElement])->getColor();
    } else if(narrativeElements[currentElement]->getType() == REMOVE_BACKGROUND_NODE) {
        color = {255,255,255,0};
    }

    if (narrativeElements[currentElement]->isDone()) {
        //TODO fix crash
        //if (narrativeElements[currentElement]->getType() == CHOICE_NODE) {
        //    narrativeElements.insert(narrativeElements.begin() + currentElement + 1, ((ChoiceNode*)narrativeElements[currentElement])->getChosenDialog().begin(), ((ChoiceNode*)narrativeElements[currentElement])->getChosenDialog().end());
        //}

        currentElement++;
    }
}

void NarrativeScene::draw() {
    if (narrativeElements.size() <= currentElement || done) {
        return;
    }

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), color);

    if (characters.size() == 1){
        DrawTextureFromCentre(characters[0]->getFront(), {(float)GetScreenWidth()/2, (float)GetScreenHeight()/2}, 2.0f, 0.0f, WHITE);
    } else if (characters.size() == 2) {
        DrawTextureFromCentre(characters[0]->getFront(), {(float)GetScreenWidth()/3, (float)GetScreenHeight()/2}, 2.0f, 0.0f, WHITE);
        DrawTextureFromCentre(characters[1]->getFront(), {(float)GetScreenWidth()/3 * 2, (float)GetScreenHeight()/2}, 2.0f, 0.0f, WHITE);
    } else if (characters.size() == 3){
        DrawTextureFromCentre(characters[0]->getFront(), {(float)GetScreenWidth()/4, (float)GetScreenHeight()/2}, 2.0f, 0.0f, WHITE);
        DrawTextureFromCentre(characters[1]->getFront(), {(float)GetScreenWidth()/2, (float)GetScreenHeight()/2}, 2.0f, 0.0f, WHITE);
        DrawTextureFromCentre(characters[2]->getFront(), {(float)GetScreenWidth()/4 * 3, (float)GetScreenHeight()/2}, 2.0f, 0.0f, WHITE);
    }
    

    if (narrativeElements[currentElement]->getType() == MOOD_NODE) {
        ((MoodNode*)narrativeElements[currentElement])->draw();
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

void NarrativeScene::addCharacter(Character* character) {
    this->characters.push_back(character);
}

void NarrativeScene::removeCharacter(Character* character) {
    for (int i = 0; i < this->characters.size(); i++) {
        if (this->characters[i] == character) {
            this->characters.erase(this->characters.begin() + i);
            return;
        }
    }
}