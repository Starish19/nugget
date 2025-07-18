#pragma once
#include "Block.h"

class mainGame : public nugget::NuggetScene {
public:
	mainGame(nugget::NuggetApplicazione* app);

	void Start() final;
	void Update(float dt) final;
	void Render() final;
	void Close() final;

private:
	Block* newBlock();
	bool blockCollision(nugget::coords at);

	nugget::grid map = nugget::grid(nugget::coords{ 0,0 }, nugget::dimensions{ 25,25 }, 16, 24);
	Block* activeBlock;
	int BlockCount = 0;

	bool pauseToggle = false;
};

