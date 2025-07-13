#pragma once
#include "nugget.h"
#include "Tetromino.h"

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
		Tetromino rotated(m_minos.size());
		for (int i = 0; i < m_minos.size(); i++) {
			mino pos = m_minos[i];
			if (!(m_grid->attemptRotate90(m_pos + pos, m_pos))) {
				pos.rotate90();
				m_pos -= pos;
				i = -1;
			}
			else rotated[i] = pos.rotate90();
		}
		m_minos = rotated;
	}

	void move(nugget::coords to) {
		for (nugget::coords pos : m_minos) {
			if (!(m_grid->attemptMove(m_pos + pos, to))) {
				return;
			}
		}
		m_pos += to;
	}

	bool checkGround() {
		for (nugget::coords pos : m_minos) {
			if (!(m_grid->attemptMove(m_pos + pos, m_pos + nugget::coords{0,1}))) {
				return true;
			}
		}
		return false;
	}

protected:
	Tetromino m_minos;
};