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

		void setWindowParams(int width, int height, const char* title);

		int getWidth() final;
		int getHeight() final;

		void StartDrawing() final;
		void FinishDrawing() final;
		void Clear(Color color) final;

		void DrawRect(Texture2D* texture, Rectangle* rect);
		void Text(const char* text, int pos_x, int pos_y, int font_size, Color color);

	private:
		int win_width;
		int win_height;
	};

	extern RenderSystemRaylib* nugRenderSystem;
}