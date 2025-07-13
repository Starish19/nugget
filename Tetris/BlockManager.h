#pragma once
#include "nugget.h"
#include "Block.h"
#include "Tetromino.h"

class BlockManager : public nugget::GameObject {
public:
	BlockManager(nugget::grid* g) : m_grid(g) {};

	void Start() final;
	void Update(float dt) final;

	Block* newBlock();

private:
	Tetromino conglomerate;
	nugget::objectList world_objects;
	Block* activeBlock;
	nugget::grid* m_grid;
	int blockCount = 0;
};

