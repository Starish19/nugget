#pragma once
#include "nugget.h"

class Block;

class BlockManager {
public:
	BlockManager(nugget::grid* grid, nugget::coords origin);

	static std::vector<nugget::coords> conglomerate;
};

