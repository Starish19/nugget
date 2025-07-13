#include "BlockManager.h"
#include "TetrisComp.h"


void BlockManager::Start() {

}

void BlockManager::Update(float dt) {
	activeBlock->Update(dt);

	if (auto TetrisComp = activeBlock->getComponent<renderComponent_Grid_Shape>()) {
		if (TetrisComp->checkGround())
			activeBlock = newBlock();
	}
}

Block* BlockManager::newBlock() {
	switch (nugget::nugRand->getRandom(I, Z)) {
	case I:
		blocks.push_back(Block(m_grid, I_TETROMINO, I_COLOR));
	case J:
		blocks.push_back(Block(m_grid, J_TETROMINO, J_COLOR));
	case L:
		blocks.push_back(Block(m_grid, L_TETROMINO, L_COLOR));
	case O:
		blocks.push_back(Block(m_grid, O_TETROMINO, O_COLOR));
	case S:
		blocks.push_back(Block(m_grid, S_TETROMINO, S_COLOR));
	case T:
		blocks.push_back(Block(m_grid, T_TETROMINO, T_COLOR));
	case Z:
		blocks.push_back(Block(m_grid, Z_TETROMINO, Z_COLOR));
	default:
		break;
	}
	return &blocks[blocks.size() - 1];
}