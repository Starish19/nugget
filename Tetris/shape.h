#pragma once
#include "nugget.h"
#include "Block.h"

class shape : public nugget::GameObject, public Block
{
public:
	shape(nugget::grid* grid, nugget::coords origin, int color);
	~shape();

	void Start() final;
	void Update(float dt) final;

private:
	std::vector<std::unique_ptr<Block>> blocks;
};

