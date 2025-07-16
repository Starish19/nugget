#pragma once
#include "nugget.h"
#include "Tetromino.h"

struct renderComponent_Grid_Shape : public nugget::renderComponent_Grid{
	renderComponent_Grid_Shape(nugget::GameObject* g) : renderComponent_Grid(g) {}

	void Render() final {
		if (!m_tex || !m_grid) return;
		for (nugget::coords pos : getMinos()) {
			pos = m_grid->getCellPosition(pos.posX, pos.posY);
			m_rect.x = pos.posX;
			m_rect.y = pos.posY;
			nugget::nugRender->Draw(m_tex, m_rect);
		}
	}

	void setShape(Tetromino minos) {
		m_minos = minos;
	}

	void rotate90() {
		Tetromino rotated(m_minos.size());
		for (int i = 0; i < m_minos.size(); i++) {
			mino pos = m_minos[i];
			if (m_grid->attemptRotate90(m_pos + pos, m_pos)) {
				pos.rotate90();
				m_pos -= pos;
				i = -1;
			}
			else rotated[i] = pos.rotate90();
		}
		m_minos = rotated;
	}

	void move(nugget::coords to) {
		for (nugget::coords pos : getMinos()) {
			if (m_grid->attemptMove(pos, to)) {
				return;
			}
		}
		m_pos += to;
	}

	bool checkGround() {
		for (nugget::coords pos : getMinos()) {
			if (m_grid->attemptMove(pos, nugget::coords{0,1})) {
				return true;
			}
		}
		return false;
	}

	bool checkCollision(Tetromino block, nugget::coords at) {
		for (nugget::coords pos : getMinos()) {
			for (nugget::coords mino : block) {
				if (mino - pos == at) {
					return true;
				}
			}
		}
		return false;
	}

	Tetromino getMinos() {
		Tetromino minos;
		for (mino m : m_minos) {
			minos.push_back(m + m_pos);
		}
		return minos;
	}

protected:
	Tetromino m_minos;
};