#include "stdafx.h"
#include "raylib.h"
#include "Components.h"


nugget::renderComponent_Rect::renderComponent_Rect(GameObject* g) : Renderable(g) {
	rect = new Rectangle;
	setRect();
}

void nugget::renderComponent_Rect::setRect(float x, float y, float width, float height) {
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
}

void nugget::renderComponent_Rect::setRect(RectValue item, float value) {
	switch (item)
	{
	case X:
		rect->x = value;
		break;
	case Y:
		rect->y = value;
		break;
	case WIDTH:
		rect->width = value;
		break;
	case HEIGHT:
		rect->height = value;
		break;
	default:
		break;
	}
}

float nugget::renderComponent_Rect::getRect(RectValue item) {
	switch (item)
	{
	case X:
		return rect->x;
	case Y:
		return rect->y;
	case WIDTH:
		return rect->width;
	case HEIGHT:
		return rect->height;
	default:
		break;
	}
	return -1;
}

nugget::renderComponent_Text::renderComponent_Text(GameObject* g) : Renderable(g) {
	color = new Color;
	setColor();
}

void nugget::renderComponent_Text::setColor(int r, int g, int b, int a) {
	*color = Color{unsigned char(r), unsigned char(g), unsigned char(b), unsigned char(a)};
}