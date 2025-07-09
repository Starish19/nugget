#pragma once
#include "subsystem.h"

//Forward Declarations
struct Color; 
struct Texture;
struct Rectangle;

namespace nugget {
	//abstract Render Class
	class RenderSystem : public subsystem
	{
	public: 
		//After Init creates default window, set custom parameters
		virtual void setWindowParams(int width, int height, const char* title) = 0;
		virtual void setClear(Color color) = 0;

		virtual int getWidth() = 0; // Window Width
		virtual int getHeight() = 0; // Window Height

		virtual void StartDrawing() = 0; // Prepare Frame Buffer
		virtual void FinishDrawing() = 0; // Swap buffers

		virtual void Draw(Texture* texture, int posX, int posY) = 0;
		virtual void Draw(Texture* texture, Rectangle* dimensions) = 0; //Draw Rectangle
		virtual void Text(const char* text, int pos_x, int pos_y, int font_size, Color color) = 0; //Write text at position
	protected:
		int win_width;
		int win_height;
	};

	// Global Instance of Renderer
	extern RenderSystem* nugRender;
}
