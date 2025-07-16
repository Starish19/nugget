#pragma once
#include "RenderSystem.h"
#include "raylib.h"

namespace nugget {
	class RenderSystemRaylib : public RenderSystem
	{
	public:
		RenderSystemRaylib();
		~RenderSystemRaylib();

		void Initalize() final;
		void Shutdown() final;

		void setWindowParams(int width, int height, const char* title) final;
		void setWindowIcon(Image* img) final;
		void setClear(Color color) final;
		void setFPS(int frams) final;
		bool closeWindow() final;

		float getDeltaTime() final;

		int getWidth() final;
		int getHeight() final;

		void StartDrawing() final;
		void FinishDrawing() final;

		void Draw(Rectangle rect, Color color) final;
		void Draw(Texture2D* texture, int posX, int posY) final;
		void Draw(Texture2D* texture, Rectangle rect) final;
		void Text(const char* text, int pos_x, int pos_y, int font_size, Color color) final;
	private:
		RAYLIB_H::Color toRaylibColor(Color color) {
			return RAYLIB_H::Color{ color.r, color.g, color.b, color.a };
		}
		RAYLIB_H::Rectangle toRaylibRect(Rectangle rect) {
			return RAYLIB_H::Rectangle{(float)rect.x, (float)rect.y, (float)rect.width, (float)rect.height};
		}
	};
}