#pragma once
#include "BaseComponent.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourceSystem.h"
#include "AudioSystem.h"

namespace nugget{
	struct inputComponent : public Component {
		inputComponent(GameObject* g) : Component(g) {}

		void Start() override {}
		void Update(float dt) override { nugInput->KeyList(keys); }

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

	typedef enum {X,Y,WIDTH,HEIGHT}RectValue;

	struct renderComponent_Rect : public Renderable {
		renderComponent_Rect(GameObject* g) : Renderable(g) {setRect(0,0,0,0);}
		~renderComponent_Rect() {
			delete rect;
		}

		void Start() override {}
		void Update(float dt) override {}
		void Render() override {nugRender->Draw(tex, rect); }

		virtual void setTexture(const std::string img_id) {
			tex = nugResource->getTextureFromImage(img_id);
		}

		virtual void setRect(float x, float y, float width, float height);
		virtual void setRect(RectValue item, float value);
		virtual float getRect(RectValue item);

	private:
		Texture* tex = nullptr;
		Rectangle* rect = nullptr;
	};

	struct audioComponent : public Component {
		audioComponent(GameObject* g) : Component(g) {}
		~audioComponent() {}

		void Start() override {}
		void Update(float dt) override {nugAudio->PlayNoise(snd);}

		void SetSound(const std::string snd_id) {
			snd = nugResource->getSoundFromWave(snd_id);
		}

	private:
		Sound* snd = nullptr;
	};

	struct TimeKeep : public nugget::Component {
		TimeKeep(nugget::GameObject* g) : Component(g) {}
		~TimeKeep() {}

		void Start() override {init_delays = delays;}
		void Update(float dt) override {
			totalTime += dt;
			for (int i = 0; i < delays.size() && i < events.size(); i++) {
				if (totalTime > delays[i]) {
					delays[i] += init_delays[i];
					events[i]();
				}
			}
		}

		void addTrigger(std::function<void()> event, float delay) {
			events.push_back(event);
			delays.push_back(delay);
		}

	private:
		float totalTime = 0;
		std::vector<std::function<void()>> events;
		std::vector<float> delays;
		std::vector<float> init_delays;
	};
}