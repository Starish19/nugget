#include "stdafx.h"
#include "RenderSystemRaylib.h"
#include "Components.h"

#ifdef RENDERSYSTEM_RAYLIB
	nugget::RenderSystemRaylib nugRenderSystemRaylib;
	nugget::RenderSystem* nugget::nugRender = &nugRenderSystemRaylib;
#endif


nugget::RenderSystemRaylib::RenderSystemRaylib() {

}

nugget::RenderSystemRaylib::~RenderSystemRaylib() {

}

void nugget::RenderSystemRaylib::Initalize() {
	InitWindow(600,900,"Nugget Engine");
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

void nugget::RenderSystemRaylib::setClear(Color color) {
	Clear = color;
}

int nugget::RenderSystemRaylib::getWidth() {
	return win_width;
}

int nugget::RenderSystemRaylib::getHeight() {
	return win_height;
}

void nugget::RenderSystemRaylib::StartDrawing() {
	BeginDrawing();
	ClearBackground(toRaylibColor(Clear));

}

void nugget::RenderSystemRaylib::FinishDrawing() {
	EndDrawing();
}

void nugget::RenderSystemRaylib::Draw(Texture2D* texture, int posX, int posY) {
	DrawTexture(*texture, posX, posY, RAYLIB_H::WHITE);
}

void nugget::RenderSystemRaylib::Draw(Texture2D* texture, Rectangle rect) {
	SetShapesTexture(*texture, RAYLIB_H::Rectangle{0, 0, (float)texture->width, (float)texture->height });
	DrawRectangleRec(toRaylibRect(rect), RAYLIB_H::WHITE);
	SetShapesTexture(Texture(), RAYLIB_H::Rectangle());
}

void nugget::RenderSystemRaylib::Draw(Rectangle rect, Color color) {
	DrawRectangleRec(toRaylibRect(rect), RAYLIB_H::Color{color.r, color.g, color.b, color.a});
}

void nugget::RenderSystemRaylib::Text(const char* text, int pos_x, int pos_y, int font_size, Color color) {
	DrawText(text, pos_x, pos_y, font_size, toRaylibColor(color));
}