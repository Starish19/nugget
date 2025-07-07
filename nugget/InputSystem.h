#pragma once
#include "subsystem.h"

//Forward Declarations
struct Vector2;
enum KeyboardKey : int;

namespace nugget {
	//Abstract Input System
	class InputSystem : public subsystem
	{
	public:
		virtual bool KeyPressed(int key) = 0; // Key pressed once
		virtual void KeyList(int* keys) = 0; // Checks if keys are down from a list

		virtual bool MousePressed(int button) = 0; // Mouse button pressed once
		virtual Vector2 MousePos() = 0; // Mouse position in window
	};

	// Global instance of Input system
	extern InputSystem* nugInput;
}

