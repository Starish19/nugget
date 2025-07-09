#include "stdafx.h"
#include "raylib.h"
#include "Components.h"


void nugget::renderComponent_Rect::setRect(float x, float y, float width, float height) {
	rect = new Rectangle{ x, y, width, height };
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