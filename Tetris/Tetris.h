#pragma once
#include "Block.h"

class Tetris : public nugget::NuggetApplicazione
{
	void Start() final;
	void Update(float dt) final;
	void Render() final;

private:
	Block* newBlock();

	nugget::grid map = nugget::grid(nugget::coords{50,50}, nugget::dimensions{25,25}, 10, 10);
	Block* activeBlock;
	int BlockCount = 0;
};

