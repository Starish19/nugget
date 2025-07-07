#pragma once
#include "BaseComponent.h"
#include "InputSystem.h"

namespace nugget{

	struct inputComponent : public Component {
		inputComponent(GameObject* g, std::vector<int> k) : Component(g) {
			for (int key : k) {
				keys[key] = false;
			}
		}

		void Start() final {}
		void Update(float dt) final { nugInput->KeyList(keys); }

	private:
		std::unordered_map<int, bool> keys;
	};
}