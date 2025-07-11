#pragma once
#include "nugget.h"
#include <iostream>

class TetrisGrid : public nugget::grid {
public:
	TetrisGrid(nugget::coords s, nugget::dimensions d, int r, int c);
	~TetrisGrid() {}

	void print() {
		for (int i = 0; i < columns; i++) {
			std::cout << "[ ";
			for (int j = 0; j < rows; j++) {
				std::cout << std::to_string(occupancy[i][j]) << ", ";
			}
			std::cout << "]" << std::endl;
		}
	}

	bool move(nugget::coords& from, nugget::coords to);

private:
	std::vector<std::vector<int>> occupancy;
};

