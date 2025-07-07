#include "nugget.h"
#include "Tetris.h"
#include <iostream>

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {

}

void Tetris::Update(float dt) {

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Update(dt);
	}

	std::cout << "Updates " << dt << std::endl;

	std::vector<int> keys = {nugget::KEY_A, nugget::KEY_W, nugget::KEY_S, nugget::KEY_D};
	
	nugget::nugInput->KeyList(keys);
	for (int key : keys) {
		switch (key)
		{
		case nugget::KEY_A:
			std::cout << "A" << std::endl;
			break;
		case nugget::KEY_D:
			std::cout << "D" << std::endl;
			break;
		case nugget::KEY_W:
			std::cout << "W" << std::endl;
			break;
		case nugget::KEY_S:
			std::cout << "S" << std::endl;
			break;
		case nugget::KEY_NULL:
			std::cout << "none" << std::endl;
			break;
		default:
			break;
		}
	}
}

void Tetris::Render() {
	
}