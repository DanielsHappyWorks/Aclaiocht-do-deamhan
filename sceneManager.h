#pragma once
#include <list>
#include "raylib.h"
#include "scene.h"

class SceneManager {
    protected:
        SceneManager();
        ~SceneManager();
        static SceneManager* sceneManager;

        Scene* defaultScene;
        Scene* currentScene;
        Scene* nextScene;
    public:
        SceneManager(SceneManager &other) = delete;
        void operator=(const SceneManager &) = delete;
        static SceneManager *GetInstance();

        Scene* getCurrentScene();
        void setCurrentScene(Scene* scene);
};