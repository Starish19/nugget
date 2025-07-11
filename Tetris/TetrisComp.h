#pragma once
#include "nugget.h"

struct renderComponent_Grid_Shape : public nugget::renderComponent_Grid{
	renderComponent_Grid_Shape(nugget::GameObject* g) : renderComponent_Grid(g) {}

	void Render() final {
		if (!tex || !m_grid) return;
		for (nugget::coords pos : m_shape) {
			pos = m_grid->getCellPosition(pos.posX, pos.posY);
			nugget::nugRender->Draw(tex, screen_pos.posX + pos.posX, screen_pos.posY + pos.posY);
		}
	}

	void setShape(std::vector<nugget::coords> shape) {
		m_shape = shape;
	}

	void rotate90() {
		for (nugget::coords& pos : m_shape) {
			pos.rotate90({0,0});
		}
	}

	void move(nugget::coords to) {
		bool ok = true;
		std::vector<nugget::coords> move;
		for (nugget::coords pos : m_shape) {
			if (ok = m_grid->attemptMove(m_pos + pos, to))
				move.push_back(pos + to);
			else return;
		}
		m_pos += to;
	}

protected:
	std::vector<nugget::coords> m_shape;
};