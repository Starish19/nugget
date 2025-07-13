#pragma once
#include "nugget.h"
#include "Block.h"
#include "Tetromino.h"

class BlockManager : public nugget::GameObject {
public:
	BlockManager() {};

	void Start() final;
	void Update(float dt) final;

	Block* newBlock();

private:
	Tetromino conglomerate;
	std::vector<Block> blocks;
	Block* activeBlock;
	nugget::grid* m_grid;
};

