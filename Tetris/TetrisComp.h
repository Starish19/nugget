#pragma once
#include "nugget.h"
#include "BlockManager.h"

struct renderComponent_Grid_Shape : public nugget::renderComponent_Grid{
	renderComponent_Grid_Shape(nugget::GameObject* g) : renderComponent_Grid(g) {}

	void Render() final {
		if (!tex || !m_grid) return;
		for (nugget::coords pos : m_minos) {
			pos = m_grid->getCellPosition(pos.posX, pos.posY);
			nugget::nugRender->Draw(tex, screen_pos.posX + pos.posX, screen_pos.posY + pos.posY);
		}
	}

	void setShape(Tetromino minos) {
		m_minos = minos;
	}

	void rotate90() {
		for (nugget::coords& pos : m_minos) {
			pos.rotate90({0,0});
		}
	}

	void move(nugget::coords to) {
		for (nugget::coords pos : m_minos) {
			if (!(m_grid->attemptMove(m_pos + pos, to)))
				return;
		}
		m_pos += to;
	}

protected:
	Tetromino m_minos;
};