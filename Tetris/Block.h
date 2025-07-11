#pragma once
#include "nugget.h"
#include "BlockManager.h"

class Block : public nugget::GameObject
{
public:
	Block(nugget::grid *grid, nugget::coords origin);
	~Block();

	void Start() override;
	void Update(float dt) override;

protected:
	nugget::grid* m_grid;
	std::vector<nugget::coords> shape;
};

