#include "scene.h"
#include "raylib.h"

class CharacterSelectScene : public Scene {
    private:
        Texture2D maleBody;
        Texture2D femaleBody;
        Texture2D background;

        Texture2D sun;
        float sun_rotation;

        Texture2D cloud_one;
        Vector2 cloud_one_pos;
        float cloud_one_scale;

        Texture2D cloud_two;
        Vector2 cloud_two_pos;
        float cloud_two_scale;

        Texture2D cloud_three;
        Vector2 cloud_three_pos;
        float cloud_three_scale;

        bool selectedGender = false;
        bool textBoxEditMode = false;
        bool characterCompleted = false;
        int toggleSliderActive = 0;
        char name[25] = "Ailbhe";

        void drawSunAtPos(Vector2 pos);
    public:
        CharacterSelectScene();
        ~CharacterSelectScene();
        void update();
        void draw();
        bool isDone();
        void debug();
};