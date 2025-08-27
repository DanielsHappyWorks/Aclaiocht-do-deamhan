#include "menuScene.h"
#include "raygui.h"
#include "fontManager.h"
#include "soundManager.h"
#include "inputManager.h"
#include "constants.h"

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

    if (IsWindowFullscreen() != fullscreen) {
        ToggleFullscreen();
    }

    if (currentResolutionIndex == NewResolutionIndex) {
        return;
    }

    switch (NewResolutionIndex) {
        case 0: SetWindowSize(800, 600); break;
        case 1: SetWindowSize(1024, 768); break;
        case 2: SetWindowSize(1440, 1080); break;
        case 3: SetWindowSize(1280, 720); break;
        case 4: SetWindowSize(1920, 1080); break;
        case 5: SetWindowSize(2560, 1440); break;
        default: break;
    }

    //Fix res when in full screen -> TODO find a better way?
    if (IsWindowFullscreen()) {
        ToggleFullscreen();
        ToggleFullscreen();
    }

    currentResolutionIndex = NewResolutionIndex;
}

void OptionsScene::draw() {
    float hight = SCREEN_HEIGHT/2 - 200;

    if (GuiWindowBox((Rectangle){SCREEN_WIDTH/2 - 200, hight, 400, 400}, "Options")) {
        done = true;
    }

    if (GuiButton((Rectangle){SCREEN_WIDTH/2 - 80, hight + 300, 160, 30}, "Exit")) {
        done = true;
    }

    //Set master volume
    GuiSliderBar((Rectangle){SCREEN_WIDTH/2, hight + 50, 160, 30}, "Master Volume", nullptr, &volume, 0, 1);
    //Set sound volume
    GuiSliderBar((Rectangle){SCREEN_WIDTH/2, hight + 90, 160, 30}, "Sound Volume", nullptr, &volumeSound, 0, 1);
    //Set music volume
    GuiSliderBar((Rectangle){SCREEN_WIDTH/2, hight + 130, 160, 30}, "Music Volume", nullptr, &volumeMusic, 0, 1);

    // Fullscreen toggle
    GuiLabel((Rectangle){SCREEN_WIDTH/2 - 107, hight + 170, 160, 30}, "Fullscreen");
    if (GuiCheckBox((Rectangle){SCREEN_WIDTH/2, hight + 170, 20, 20}, "", &fullscreen));

    // Change Resolution
    GuiLabel((Rectangle){SCREEN_WIDTH/2 - 107, hight + 210, 160, 30}, "Resolution");
    if (GuiDropdownBox((Rectangle){SCREEN_WIDTH/2, hight + 210, 160, 30}, "800x600;1024×768;1440×1080;1280x720;1920x1080;2560x1440", &NewResolutionIndex, resolutionEditMode)) resolutionEditMode = !resolutionEditMode;
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
    float hight = SCREEN_HEIGHT/2 - 200;

    if (GuiWindowBox((Rectangle){SCREEN_WIDTH/2 - 200, hight, 400, 400}, "Controls")) {
        done = true;
    }

    DrawTextEx(FontManager::GetInstance()->getFont(), "Movement: WASD or Arrow Keys", {(float)SCREEN_WIDTH/2 - 170, hight + 80}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Interact: E, Enter or mouse click", {(float)SCREEN_WIDTH/2 - 170, hight + 120}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Buttons: Mouse click", {(float)SCREEN_WIDTH/2 - 170, hight + 160}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Quit: ESC", {(float)SCREEN_WIDTH/2 - 170, hight + 200}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);

    if (GuiButton((Rectangle){SCREEN_WIDTH/2 - 80, hight + 300, 160, 30}, "Exit")) {
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
    float hight = SCREEN_HEIGHT/2 - 200;

    if (GuiWindowBox((Rectangle){SCREEN_WIDTH/2 - 200, hight, 400, 400}, "Credits")) {
        done = true;
    }

    DrawTextEx(FontManager::GetInstance()->getFont(), "Programming: Daniel Foth", {(float)SCREEN_WIDTH/2 - 170, hight + 40}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Art: Daniel Foth", {(float)SCREEN_WIDTH/2 - 170, hight + 60}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Narrative: Daniel Foth", {(float)SCREEN_WIDTH/2 - 170, hight + 80}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Music: Joel Steudler", {(float)SCREEN_WIDTH/2 - 170, hight + 100}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Sounds: Freesound \n       wakuwakuwakuwaku \n       pogmog \n       sheyvan \n       mrickey13\n       rob marion\n       adhdreaming", {(float)SCREEN_WIDTH/2 - 170, hight + 120}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);
    DrawTextEx(FontManager::GetInstance()->getFont(), "Special thanks to the DkIT \nFaculty, my wife and friends \nfor supporting me during \nthis project.", {(float)SCREEN_WIDTH/2 - 170, hight + 250}, 18, FontManager::GetInstance()->getSpacing(), DARKDARKGRAY);

    if (GuiButton((Rectangle){SCREEN_WIDTH/2 - 80, hight + 330, 160, 30}, "Exit")) {
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