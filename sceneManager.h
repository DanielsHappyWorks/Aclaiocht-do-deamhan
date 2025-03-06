#pragma once
#include <list>
#include "raylib.h"
#include "scene.h"
#include "narrativeScene.h"

class SceneManager {
    protected:
        SceneManager();
        ~SceneManager();
        static SceneManager* sceneManager;

        Scene* defaultScene;
        Scene* currentScene;
        Scene* nextScene;

        NarrativeScene* overlayScene;
    public:
        SceneManager(SceneManager &other) = delete;
        void operator=(const SceneManager &) = delete;
        static SceneManager *GetInstance();

        Scene* getCurrentScene();
        void setCurrentScene(Scene* scene);
        NarrativeScene* getSceneOverlay();
        void setSceneOverlay(NarrativeScene* scene);
};