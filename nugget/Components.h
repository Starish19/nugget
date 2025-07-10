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
		renderComponent_Rect(GameObject* g);
		~renderComponent_Rect() {
			delete rect;
		}

		void Start() override {};
		void Update(float dt) override {}
		void Render() override {if (tex) nugRender->Draw(tex, rect); }

		virtual void setTexture(const std::string img_id) {
			tex = nugResource->getTextureFromImage(img_id);
		}

		virtual void setRect(float x = 0, float y = 0, float width = 50, float height = 50);
		virtual void setRect(RectValue item, float value);
		virtual float getRect(RectValue item);

	private:
		Texture* tex = nullptr;
		Rectangle* rect = nullptr;
	};

	struct renderComponent_Text : public Renderable {
		renderComponent_Text(GameObject* g);
		~renderComponent_Text() {}

		void Start() override {}
		void Update(float dt) override {}
		void Render() override { nugRender->Text(text.c_str(), 50, 50, 50, color);}

		void setText(std::string t) {text = t;}
		void setColor(int r = 0, int g = 0, int b = 0, int a = 100);

	private:
		std::string text;
		Color* color;
	};

	struct audioComponent : public Component {
		audioComponent(GameObject* g) : Component(g) {}
		~audioComponent() {}

		void Start() override {}
		void Update(float dt) override {nugAudio->PlayNoise(snd);}

		virtual void SetSound(const std::string snd_id) {
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
					delays[i] = totalTime + init_delays[i];
					events[i]();
				}
			}
		}

		virtual void addTrigger(std::function<void()> event, float delay) {
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