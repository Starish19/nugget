#include "stdafx.h"
#include "InputSystemRaylib.h"

#ifdef INPUTSYSTEM_RAYLIB
	nugget::InputSystemRaylib nugInputSystemRaylib;
	nugget::InputSystem* nugget::nugInput = &nugInputSystemRaylib;
#endif

nugget::InputSystemRaylib::InputSystemRaylib() {

}

nugget::InputSystemRaylib::~InputSystemRaylib() {

}

void nugget::InputSystemRaylib::Initalize() {
	
}

void nugget::InputSystemRaylib::Shutdown() {

}

bool nugget::InputSystemRaylib::KeyPressed(int key) {
	return IsKeyPressed(key);
}

void nugget::InputSystemRaylib::KeyList(int* keys) {
	for (int i = 0; keys[i]; i++) {
		if (IsKeyUp(keys[i])) {
			keys[i] = 0;
		}
	}
}

bool nugget::InputSystemRaylib::MousePressed(int button) {
	return IsMouseButtonPressed(button);
}

Vector2 nugget::InputSystemRaylib::MousePos() {
	return GetMousePosition();
}