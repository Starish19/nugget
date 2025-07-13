#pragma once
#include "nugget.h"
#include "Tetromino.h"

class Block : public nugget::GameObject
{
public:
	Block(nugget::grid *grid, Tetromino minos, std::string color);
	~Block();

	void Start() override;
	void Update(float dt) override;

protected:
	nugget::grid* m_grid;
	Tetromino m_minos;
	std::string color;
};

