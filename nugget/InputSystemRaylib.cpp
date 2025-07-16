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

void nugget::InputSystemRaylib::KeyList(std::vector<int> &keys) {
	bool afk = true;
	for (int i = 0; i < keys.size(); i++) {
		if (!IsKeyDown(keys[i]))
			keys[i] = -1;
		else
			afk = false;
	}
	if (afk) keys[0] = KEY_NULL;
}

void nugget::InputSystemRaylib::KeyList(std::unordered_map<int, bool> &keys) {
	bool afk = true;
	for (auto i = keys.begin(); i != keys.end(); i++) {
		if (IsKeyDown(i->first)) {
			i->second = true;
			afk = false;
		}
		else 
			i->second = false;
	}
	keys[KEY_NULL] = afk;
}

bool nugget::InputSystemRaylib::MousePressed(int button) {
	return IsMouseButtonPressed(button);
}

nugget::coords nugget::InputSystemRaylib::MousePos() {
	Vector2 pos = GetMousePosition();
	return coords{ (int)pos.x, (int)pos.y };
}