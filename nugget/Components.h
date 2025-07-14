#pragma once
#include "BaseComponent.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourceSystem.h"
#include "AudioSystem.h"
#include "grid.h"

namespace nugget{
	struct inputComponent : public Component {
		inputComponent(GameObject* g) : Component(g) {}
		~inputComponent() {
			for (Rectangle* rect : buttons) {
				delete rect;
			}
			buttons.clear();
		}

		void Start() override {}
		void Update(float dt) override;

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

		bool getKey(int key) {
			return nugInput->KeyPressed(key);
		}

		virtual void addButton(std::function<void()> event, nugget::coords pos, nugget::dimensions dim);

	protected:
		std::unordered_map<int, bool> keys;
		nugget::coords mousePos = {0,0};
		std::vector<std::function<void()>> events;
		std::vector<Rectangle*> buttons;
	};

	struct Renderable : public Component {
		Renderable(GameObject* g) : Component(g) {}

		virtual void Render() = 0;

		bool render = true;
	};

	typedef enum {X,Y,WIDTH,HEIGHT}RectValue;

	struct renderComponent_Rect : public Renderable {
		renderComponent_Rect(GameObject* g);
		~renderComponent_Rect() {
			delete rect;
			delete color;
		}

		void Start() override {};
		void Update(float dt) override {}
		void Render() override { if (tex) nugRender->Draw(tex, rect); else nugRender->Draw(rect, color); }

		virtual void setTexture(const std::string img_id) {
			tex = nugResource->getTextureFromImage(img_id);
		}

		virtual void setRect(float x = 0, float y = 0, float width = 50, float height = 50);
		virtual void setRect(RectValue item, float value);
		virtual float getRect(RectValue item);

		void setColor(int r = 0, int g = 0, int b = 0, int a = 100);

	protected:
		Texture* tex = nullptr;
		Rectangle* rect = nullptr;
		Color* color;
	};

	struct renderComponent_Text : public Renderable {
		renderComponent_Text(GameObject* g);
		~renderComponent_Text() {
			delete color;
		}

		void Start() override {}
		void Update(float dt) override {}
		void Render() override { nugRender->Text(text.c_str(), 50, 50, 50, color);}

		void setText(std::string t) {text = t;}
		void setColor(int r = 0, int g = 0, int b = 0, int a = 100);

	protected:
		std::string text;
		Color* color;
	};

	struct renderComponent_Grid : public Renderable {
		renderComponent_Grid(GameObject* g) : Renderable(g) {}
		~renderComponent_Grid() {}

		void Start() override;
		void Update(float dt) override {}
		void Render() override {
			if (m_grid) screen_pos = m_grid->getCellPosition(m_pos.posX, m_pos.posY);
			if (tex) nugRender->Draw(tex, screen_pos.posX, screen_pos.posY);
		}

		virtual void setTexture(const std::string img_id) {
			tex = nugResource->getTextureFromImage(img_id);
		}

		void setGrid(grid* g) {m_grid = g;};

		coords m_pos{0,0};
	protected:
		Texture* tex = nullptr;
		coords screen_pos{0,0};
		grid* m_grid = nullptr;
	};

	struct audioComponent : public Component {
		audioComponent(GameObject* g) : Component(g) {}
		~audioComponent() {}

		void Start() override {}
		void Update(float dt) override {nugAudio->PlayNoise(snd);}

		virtual void SetSound(const std::string snd_id) {
			snd = nugResource->getSoundFromWave(snd_id);
		}

	protected:
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

	protected:
		float totalTime = 0;
		std::vector<std::function<void()>> events;
		std::vector<float> delays;
		std::vector<float> init_delays;
	};
}