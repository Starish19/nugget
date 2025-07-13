#include "BlockManager.h"
#include "TetrisComp.h"


void BlockManager::Start() {
	activeBlock = newBlock();
}

void BlockManager::Update(float dt) {
	activeBlock->Update(dt);

	if (auto TetrisComp = activeBlock->getComponent<renderComponent_Grid_Shape>()) {
		if (TetrisComp->checkGround()) {
			activeBlock = newBlock();
			activeBlock->Start();
		}
	}
}

Block* BlockManager::newBlock() {
	std::unique_ptr<Block> newBlock;
	switch (nugget::nugRand->getRandom(I, Z)) {
	case I:
		newBlock = std::make_unique<Block>(m_grid, I_TETROMINO, I_COLOR);
		break;
	case J:
		newBlock = std::make_unique<Block>(m_grid, J_TETROMINO, J_COLOR);
		break;
	case L:
		newBlock = std::make_unique<Block>(m_grid, L_TETROMINO, L_COLOR);
		break;
	case O:
		newBlock = std::make_unique<Block>(m_grid, O_TETROMINO, O_COLOR);
		break;
	case S:
		newBlock = std::make_unique<Block>(m_grid, S_TETROMINO, S_COLOR);
		break;
	case T:
		newBlock = std::make_unique<Block>(m_grid, T_TETROMINO, T_COLOR);
		break;
	case Z:
		newBlock = std::make_unique<Block>(m_grid, Z_TETROMINO, Z_COLOR);
		break;
	default:
		break;
	}
	Block* b = newBlock.get();
	world_objects["Block" + std::to_string(blockCount)] = std::move(newBlock);
	return b;
}