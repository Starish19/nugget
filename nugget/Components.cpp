#include "stdafx.h"
#include "raylib.h"
#include "Components.h"


nugget::renderComponent_Rect::renderComponent_Rect(GameObject* g) : Renderable(g) {
	rect = new Rectangle;
	setRect();
	color = new Color;
	setColor();
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

void nugget::renderComponent_Grid::Start() {
	if (m_grid) {
		dimensions dims = m_grid->getCellDimensions();
		tex->width = dims.width;
		tex->height = dims.Height;
	}
}

void nugget::inputComponent::Update(float dt) {
	nugInput->KeyList(keys);
	Vector2 pos = nugInput->MousePos();
	mousePos = nugget::coords{ (int)pos.x, (int)pos.y };

	for (int i = 0; i < events.size() && i < buttons.size(); i++) {
		nugget::coords buttonPos{ (int)buttons[i]->x, (int)buttons[i]->y };
		nugget::coords buttonDim{ (int)buttons[i]->width, (int)buttons[i]->height };
		if (mousePos.posX > buttonPos.posX && mousePos.posY > buttonPos.posY && (buttonPos + buttonDim).posX > mousePos.posX && (buttonPos + buttonDim).posY > mousePos.posY && nugInput->MousePressed(MOUSE_BUTTON_LEFT)) {
			events[i]();
		}
	}
}

void nugget::inputComponent::addButton(std::function<void()> event, nugget::coords pos, nugget::dimensions dim) {
	events.push_back(event);
	Rectangle* rect = new Rectangle{ (float)pos.posX, (float)pos.posY, (float)dim.width, (float)dim.Height };
	buttons.push_back(rect);
}

void nugget::renderComponent_Rect::setColor(int r, int g, int b, int a) {
	*color = Color{ unsigned char(r), unsigned char(g), unsigned char(b), unsigned char(a) };
}