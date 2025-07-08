#include "nugget.h"
#include "Tetris.h"
#include "Block.h"
#include <iostream>

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {
	std::unique_ptr<Block>first_block = std::make_unique<Block>();
	m_objects["firstBlock"] = std::move(first_block);

	first_block = std::make_unique<Block>();
	m_objects["secondBlock"] = std::move(first_block);

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Start();
	}
}

void Tetris::Update(float dt) {

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Update(dt);
	}

	std::cout << "Updates " << dt << std::endl;
}

void Tetris::Render() {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		if (auto renderable = it->second->getComponent<nugget::Renderable>()) {
			renderable->Render();
		}
	}
}