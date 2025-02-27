#include "scene.h"
#include "raylib.h"

class CharacterSelectScene : public Scene {
    private:
        Texture2D maleBody;
        Texture2D femaleBody;

        bool selectedGender = false;
        bool textBoxEditMode = false;
        bool characterCompleted = false;
        int toggleSliderActive = 0;
        char name[25] = "Ailbhe";

    public:
        CharacterSelectScene();
        ~CharacterSelectScene();
        void update();
        void draw();
        bool isDone();
        void debug();
};