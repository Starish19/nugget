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
        void KeyList(std::vector<int> &keys) final;
        void KeyList(std::unordered_map<int, bool> &keys) final;

        bool MousePressed(int button) final;
        coords MousePos() final;
    };
}