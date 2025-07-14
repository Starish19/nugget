#pragma once
#include "Block.h"

class Tetris : public nugget::NuggetApplicazione
{
	void Initalize() final;
	void Update(float dt) final;
	void Render() final;
	void Shutdown() final {}
};

