#include "nugget.h"
#include "Tetris.h"
#include <iostream>

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {

}

void Tetris::Update(float dt) {
	std::cout << "Updates " << dt << std::endl;

	int keys[2] = {65, 0};
	
	nugget::nugInput->KeyList(keys);
	if (keys[0] == 65) std::cout << "A" << std::endl;
}

void Tetris::Render() {
	
}