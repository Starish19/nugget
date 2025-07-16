#pragma once
#include "BaseComponent.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourceSystem.h"
#include "AudioSystem.h"
#include "grid.h"

namespace nugget{
	//InputComponent
	struct inputComponent : public Component {
		inputComponent(GameObject* g) : Component(g) {}
		~inputComponent() {}

		void Start() override {}
		void Update(float dt) {
			nugInput->KeyList(keys);
			coords mousePos = nugInput->MousePos();
			for (int i = 0; i < events.size() && i < buttons.size(); i++) {
				nugget::coords buttonPos{ (int)buttons[i].x, (int)buttons[i].y };
				nugget::coords buttonDim{ (int)buttons[i].width, (int)buttons[i].height };
				if (mousePos.posX > buttonPos.posX && mousePos.posY > buttonPos.posY && (buttonPos + buttonDim).posX > mousePos.posX && (buttonPos + buttonDim).posY > mousePos.posY && nugInput->MousePressed(MOUSE_BUTTON_LEFT)) {
					events[i]();
				}
			}
		}

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

		void addButton(std::function<void()> event, Rectangle rect) {
			events.push_back(event);
			buttons.push_back(rect);
		}

	protected:
		std::unordered_map<int, bool> keys;
		nugget::coords mousePos = {0,0};
		std::vector<std::function<void()>> events;
		std::vector<Rectangle> buttons;
	};

	//AbstactRenderComponent
	struct Renderable : public Component {
		Renderable(GameObject* g) : Component(g) {}

		virtual void Render() = 0;

		bool render = true;
	};

	//RenderComponentRect
	struct renderComponent_Rect : public Renderable {
		renderComponent_Rect(GameObject* g) : Renderable(g) {};
		~renderComponent_Rect() {}

		void Start() override {};
		void Update(float dt) override {}
		void Render() override {
			if (m_tex) nugRender->Draw(m_tex, m_rect); 
			else nugRender->Draw(m_rect, m_color); 
		}

		virtual void setTexture(const std::string img_id) {m_tex = nugResource->getTextureFromImage(img_id);}

		virtual void setRect(Rectangle rect) { m_rect = rect; }
		void setColor(Color color = { 0,0,0,255 }) { m_color = color; }

	protected:
		Texture* m_tex = nullptr;
		Rectangle m_rect{0,0,50,50};
		Color m_color{0,0,0,255};
	};

	//RenderComponentText
	struct renderComponent_Text : public Renderable {
		renderComponent_Text(GameObject* g) : Renderable(g) {}
		~renderComponent_Text() {}

		void Start() override {}
		void Update(float dt) override {}
		void Render() override { nugRender->Text(text.c_str(), pos.posX, pos.posY, size, color);}

		void setText(std::string t) {text = t;}
		void setPos(coords p) { pos = p; }
		void setSize(int s) { size = s; }
		void setColor(Color c) { color = c; }

	protected:
		std::string text = "";
		coords pos{50,50};
		Color color{ 200,200,200,100 };
		int size = 50;
	};

	//RenderComponentGrid
	struct renderComponent_Grid : public renderComponent_Rect {
		renderComponent_Grid(GameObject* g) : renderComponent_Rect(g) {}
		~renderComponent_Grid() {}

		void Start() override {
			if (m_grid) {
				dimensions dims = m_grid->getCellDimensions();
				m_rect.width = dims.width;
				m_rect.height = dims.Height;
			}
		}
		void Update(float dt) override {}
		void Render() override {
			if (m_grid) { 
				coords screen_pos = m_grid->getCellPosition(m_pos.posX, m_pos.posY); 
				m_rect.x = screen_pos.posX;
				m_rect.y = screen_pos.posY;
			}
			if (m_tex) nugRender->Draw(m_tex, m_rect);
		}

		virtual void setTexture(const std::string img_id) {
			m_tex = nugResource->getTextureFromImage(img_id);
		}

		void setGrid(grid* g) {m_grid = g;};

		coords m_pos{0,0};
	protected:
		grid* m_grid = nullptr;
	};

	//AudioComponent
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

	//TimeKeepComponent
	struct TimeKeepComponent : public nugget::Component {
		TimeKeepComponent(nugget::GameObject* g) : Component(g) {}
		~TimeKeepComponent() {}

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