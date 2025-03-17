#include "menuScene.h"
#include "raygui.h"
#include "fontManager.h"
#include "soundManager.h"
#include "inputManager.h"

OptionsScene::OptionsScene() {
    volume = SoundManager::GetInstance()->getVolume();
    volumeSound = SoundManager::GetInstance()->getVolumeSound();
    volumeMusic = SoundManager::GetInstance()->getVolumeMusic();
}

OptionsScene::~OptionsScene() {}

void OptionsScene::update() {
    if (InputManager::GetInstance()->isInteractingWithKeyboard()) {
        done = true;
    }

    SoundManager::GetInstance()->setVolume(volume);
    SoundManager::GetInstance()->setVolumeSound(volumeSound);
    SoundManager::GetInstance()->setVolumeMusic(volumeMusic);
}

void OptionsScene::draw() {
    float hight = GetScreenHeight()/2 - 200;

    if (GuiWindowBox((Rectangle){GetScreenWidth()/2 - 200, hight, 400, 400}, "Options")) {
        done = true;
    }

    //Set master volume
    GuiSliderBar((Rectangle){GetScreenWidth()/2, hight + 100, 160, 30}, "Master Volume", nullptr, &volume, 0, 1);
    //Set sound volume
    GuiSliderBar((Rectangle){GetScreenWidth()/2, hight + 150, 160, 30}, "Sound Volume", nullptr, &volumeSound, 0, 1);
    //Set music volume
    GuiSliderBar((Rectangle){GetScreenWidth()/2, hight + 200, 160, 30}, "Music Volume", nullptr, &volumeMusic, 0, 1);

    if (GuiButton((Rectangle){GetScreenWidth()/2 - 80, hight + 300, 160, 30}, "Exit")) {
        done = true;
    }
}

bool OptionsScene::isDone() {
    if (done) {
        SoundManager::GetInstance()->playSound(SFX_CLICK);
    }
    return done;
}

bool OptionsScene::isDoneAtLoc() {
    return false;
}

void OptionsScene::debug() {}

ControlsScene::ControlsScene() {
}

ControlsScene::~ControlsScene() {}

void ControlsScene::update() {
    if (InputManager::GetInstance()->isInteractingWithKeyboard()) {
        done = true;
    }
}

void ControlsScene::draw() {
    float hight = GetScreenHeight()/2 - 200;

    if (GuiWindowBox((Rectangle){GetScreenWidth()/2 - 200, hight, 400, 400}, "Controls")) {
        done = true;
    }

    DrawTextEx(FontManager::GetInstance()->getFont(), "Movement: WASD or Arrow Keys", {(float)GetScreenWidth()/2 - 170, hight + 80}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Interact: E, Enter or mouse click", {(float)GetScreenWidth()/2 - 170, hight + 120}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Buttons: Mouse click", {(float)GetScreenWidth()/2 - 170, hight + 160}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Quit: ESC", {(float)GetScreenWidth()/2 - 170, hight + 200}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);

    if (GuiButton((Rectangle){GetScreenWidth()/2 - 80, hight + 300, 160, 30}, "Exit")) {
        done = true;
    }
}

bool ControlsScene::isDone() {
    if (done) {
        SoundManager::GetInstance()->playSound(SFX_CLICK);
    }
    return done;
}

bool ControlsScene::isDoneAtLoc() {
    return false;
}

void ControlsScene::debug() {}

CreditsScene::CreditsScene() {
}

CreditsScene::~CreditsScene() {}

void CreditsScene::update() {
    if (InputManager::GetInstance()->isInteractingWithKeyboard()) {
        done = true;
    }
}

void CreditsScene::draw() {
    float hight = GetScreenHeight()/2 - 200;

    if (GuiWindowBox((Rectangle){GetScreenWidth()/2 - 200, hight, 400, 400}, "Credits")) {
        done = true;
    }

    DrawTextEx(FontManager::GetInstance()->getFont(), "Programming: Daniel Foth", {(float)GetScreenWidth()/2 - 170, hight + 40}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Art: Daniel Foth", {(float)GetScreenWidth()/2 - 170, hight + 60}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Narrative: Daniel Foth", {(float)GetScreenWidth()/2 - 170, hight + 80}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Music: Joel Steudler", {(float)GetScreenWidth()/2 - 170, hight + 100}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Sounds: Freesound \n       wakuwakuwakuwaku \n       pogmog \n       sheyvan \n       mrickey13\n       rob marion\n       adhdreaming", {(float)GetScreenWidth()/2 - 170, hight + 120}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Special thanks to the DkIT \nFaculty, my wife and friends \nfor supporting me during \nthis project.", {(float)GetScreenWidth()/2 - 170, hight + 250}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);

    if (GuiButton((Rectangle){GetScreenWidth()/2 - 80, hight + 330, 160, 30}, "Exit")) {
        done = true;
    }
}

bool CreditsScene::isDone() {
    if (done) {
        SoundManager::GetInstance()->playSound(SFX_CLICK);
    }
    return done;
}

bool CreditsScene::isDoneAtLoc() {
    return false;
}

void CreditsScene::debug() {}