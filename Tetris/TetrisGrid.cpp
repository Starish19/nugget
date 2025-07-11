#include "TetrisGrid.h"

TetrisGrid::TetrisGrid(nugget::coords s, nugget::dimensions d, int r, int c) : nugget::grid(s, d, r, c) {
	for (int i = 0; i < c; i++) {
		occupancy.push_back(std::vector<int>());
		for (int j = 0; j < r; j++) {
			occupancy[i].push_back(0);
		}
	}
}

bool TetrisGrid::move(nugget::coords& from, nugget::coords to) {
	to.posX = std::min(std::max(to.posX, 0), rows -1);
	to.posY = std::min(std::max(to.posY, 0), columns- 1);
	if (occupancy[to.posY][to.posX] == 1) {
		return false;
	}
	else {
		occupancy[to.posY][to.posX] = 2;
		return true;
	}
}