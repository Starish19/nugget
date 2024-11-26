#include "RenderSystemRaylib.h"

nugget::RenderSystemRaylib nugRenderSystemRaylib;
nugget::RenderSystem* nugget::nugRender = &nugRenderSystemRaylib;

nugget::RenderSystemRaylib::RenderSystemRaylib() {

}

nugget::RenderSystemRaylib::~RenderSystemRaylib() {

}

void nugget::RenderSystemRaylib::Initalize() {
	InitWindow(600,600,"Default");
}

void nugget::RenderSystemRaylib::Shutdown() {
	CloseWindow();
}

void nugget::RenderSystemRaylib::setWindowParams(int width, int height, const char* title) {
	win_width = width;
	win_height = height;
	SetWindowSize(width, height);
	SetWindowTitle(title);
}

int nugget::RenderSystemRaylib::getWidth() {
	return win_width;
}

int nugget::RenderSystemRaylib::getHeight() {
	return win_height;
}

void nugget::RenderSystemRaylib::StartDrawing() {
	BeginDrawing();
}

void nugget::RenderSystemRaylib::FinishDrawing() {
	EndDrawing();
}

void nugget::RenderSystemRaylib::Clear(Color color) {
	ClearBackground(color);
}

void nugget::RenderSystemRaylib::DrawRect(Texture2D* texture, Rectangle* rect) {
	SetShapesTexture(*texture, Rectangle{ 0,0, (float)texture->width, (float)texture->height });
	DrawRectangleRec(*rect, WHITE);
}

void nugget::RenderSystemRaylib::Text(const char* text, int pos_x, int pos_y, int font_size, Color color) {
	DrawText(text, pos_x, pos_y, font_size, color);
}