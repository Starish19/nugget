#pragma once
#include "TetrisGrid.h"
#include "nugget.h"

class Block : public nugget::GameObject
{
public:
	Block(TetrisGrid* grid, nugget::coords origin);
	~Block();

	void Start() override;
	void Update(float dt) override;

	void setPos(nugget::coords pos) {
		m_origin = pos;
	}

protected:
	TetrisGrid* m_grid;
	nugget::coords m_origin;
	std::vector<nugget::coords> shape;
};

