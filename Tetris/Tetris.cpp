#include "nugget.h"
#include "Tetris.h"
#include "Block.h"
#include <iostream>

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {
	std::unique_ptr<Block>first_block = std::make_unique<Block>();
	m_objects["firstBlock"] = std::move(first_block);

	nugget::nugResource->addFile("images", "assets.zip");

	nugget::nugResource->LoadImage("mudkip", "images", "assets/images/mudkip.png");
	nugget::nugResource->LoadImage("argh", "images", "assets/images/th.jpg");
	nugget::nugResource->LoadImage("red", "images", "assets/images/RedRubix.png");
	nugget::nugResource->LoadImage("test", "images", "assets/images/test.png");

	nugget::nugResource->LoadWave("yipee", "images", "assets/audio/yipee.mp3");
	nugget::nugResource->getSoundFromWave("yipee");

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Start();
	}
}

void Tetris::Update(float dt) {

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Update(dt);
	}

	//std::cout << "Updates " << dt << std::endl;
}

void Tetris::Render() {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		if (auto renderable = it->second->getComponent<nugget::renderComponent_Rect>()) {
			renderable->Render();
		}
	}
}