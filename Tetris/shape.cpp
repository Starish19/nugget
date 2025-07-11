#include "shape.h"

shape::shape(TetrisGrid* grid, nugget::coords origin, int color) : Block(grid, origin) {

}

shape::~shape() {

}

void shape::Start() {
	/*int j = 0;
	std::unique_ptr<Block> block = std::make_unique<Block>(&m_grid, nugget::coords{ 0,0 }, j++);
	blocks.push_back(std::move(block));
	for (int i = 2; i > 0; i--) {
		block = std::make_unique<Block>(&m_grid, nugget::coords{ -i,0 }, j++);
		blocks.push_back(std::move(block));

		block = std::make_unique<Block>(&m_grid, nugget::coords{ 0,-i }, j++);
		blocks.push_back(std::move(block));
	}*/
}

void shape::Update(float dt) {

}