#pragma once
#include "TetrisGrid.h"

class Tetris : public nugget::NuggetApplicazione
{
	void Start() final;
	void Update(float dt) final;
	void Render() final;

private:
	TetrisGrid map = TetrisGrid({50,50}, {25,25}, 10, 20);
};

