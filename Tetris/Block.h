#pragma once
#include "BaseGameObject.h"
#include "grid.h"

class Block : public nugget::GameObject
{
public:
	Block(nugget::grid* grid);
	~Block();

	void Start() final;
	void Update(float dt) final ;

private:
	nugget::grid* m_grid;
};

