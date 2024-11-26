#pragma once
#include "raylib.h"
#include "InputSystem.h"

namespace nugget {

    class InputSystemRaylib : public InputSystem
    {
    public:
        InputSystemRaylib();
        ~InputSystemRaylib();

        void Initalize() final;
        void Shutdown() final;

        bool KeyPressed(int key) final;
        void KeyList(int* keys) final;

        bool MousePressed(int button) final;
        Vector2 MousePos() final;
    };
}