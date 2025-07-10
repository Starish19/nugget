#pragma once
#include "raylib.h"
#include "RenderSystem.h"

namespace nugget {
	class RenderSystemRaylib : public RenderSystem
	{
	public:
		RenderSystemRaylib();
		~RenderSystemRaylib();

		void Initalize() final;
		void Shutdown() final;

		void setWindowParams(int width, int height, const char* title) final;
		void setClear(Color color) final;

		int getWidth() final;
		int getHeight() final;

		void StartDrawing() final;
		void FinishDrawing() final;

		void Draw(Texture2D* texture, int posX, int posY) final;
		void Draw(Texture2D* texture, Rectangle* rect) final;
		void Text(const char* text, int pos_x, int pos_y, int font_size, Color* color) final;
	private:
		Color Clear;
	};
}