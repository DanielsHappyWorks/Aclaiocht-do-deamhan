#include "sceneManager.h"
#include "characterSelectScene.h"
#include "overworldScene.h"
#include "locationScene.h"
#include "locationFactory.h"

SceneManager* SceneManager::sceneManager = nullptr;

SceneManager *SceneManager::GetInstance()
{
    if(sceneManager==nullptr){
        sceneManager = new SceneManager();
    }
    return sceneManager;
}

SceneManager::SceneManager() {
    overlayScene = nullptr;
    defaultScene = new OverworldScene();
    currentScene = new CharacterSelectScene();
}

SceneManager::~SceneManager() {

}

Scene* SceneManager::getCurrentScene() {
    if (currentScene != nullptr) {
        if (currentScene == defaultScene && nextScene != nullptr) {
            currentScene = nextScene;
            nextScene = nullptr;
        } else if (currentScene->isDone() && nextScene != nullptr) {
            //currentScene->destroy();
            currentScene = nextScene;
            nextScene = nullptr;
        } else if (currentScene->isDone()) {
            //currentScene->destroy();
            currentScene = defaultScene;
        }
    }

    return currentScene;
}

void SceneManager::setCurrentScene(Scene* scene) {
    //this->nextScene->destroy();
    this->nextScene = scene;
}


//TODO maybe change the scene to a stack?
NarrativeScene* SceneManager::getSceneOverlay() {
    if (overlayScene == nullptr) {
        return overlayScene;
    }

    if (overlayScene->isDone()) {
        if (overlayScene->isDoneAtLoc()) {
            //currentScene->destroy();
            currentScene = defaultScene;
        }
        overlayScene = nullptr;
    }

    return overlayScene;
}

void SceneManager::setSceneOverlay(NarrativeScene* scene) {
    overlayScene = scene;
}