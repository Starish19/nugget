#pragma once
#include "BaseComponent.h"
#include "InputSystem.h"
#include "ResourceSystem.h"
#include "RenderSystem.h"

namespace nugget{
	struct inputComponent : public Component {
		inputComponent(GameObject* g) : Component(g) {}

		void Start() final {}
		void Update(float dt) final { nugInput->KeyList(keys); }

		void setKeys(std::vector<int> k) {
			for (int key : k) {
				keys[key] = false;
			}
		}

		std::vector<int> getKeys() {
			std::vector<int> activeKeys;
			for (auto k = keys.begin(); k != keys.end(); k++) {
				if (k->second) activeKeys.push_back(k->first);
			}
			return activeKeys;
		}

	private:
		std::unordered_map<int, bool> keys;
	};

	struct Renderable : public Component {
		Renderable(GameObject* g) : Component(g) {}

		virtual void Render() = 0;
	};

	struct renderComponent_Rect : public Renderable {
		renderComponent_Rect(GameObject* g) : Renderable(g) {}

		void Start() final {}
		void Update(float dt) final {}
		void Render() {nugRender->DrawRect(tex, rect); }

		void setTexture(const std::string img_id) {
			tex = &nugResource->getTextureFromImage(img_id);
		}

		Rectangle* rect;
	private:
		Texture* tex;
	};
}