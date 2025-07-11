#include "nugget.h"
#include "Tetris.h"
#include "Block.h"
#include <iostream>

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {
	std::unique_ptr<Block> block = std::make_unique<Block>(&map, nugget::coords{3,3});
	m_objects["Block_0_0"] = std::move(block);

	nugget::nugResource->addFile("assets", "assets.zip");

	nugget::nugResource->LoadImage("mudkip", "assets", "assets/images/mudkip.png");
	nugget::nugResource->LoadImage("argh", "assets", "assets/images/th.jpg");
	nugget::nugResource->LoadImage("red", "assets", "assets/images/RedRubix.png");
	nugget::nugResource->LoadImage("blue", "assets", "assets/images/BlueRubix.png");
	nugget::nugResource->LoadImage("green", "assets", "assets/images/GreenRubix.png");
	nugget::nugResource->LoadImage("yellow", "assets", "assets/images/YellowRubix.png");
	nugget::nugResource->LoadImage("purple", "assets", "assets/images/PurpleRubix.png");
	nugget::nugResource->LoadImage("test", "assets", "assets/images/test.png");

	nugget::nugResource->LoadWave("yipee", "assets", "assets/audio/yipee.mp3");
	nugget::nugResource->getSoundFromWave("yipee");

	std::unique_ptr<nugget::GameObject> text = std::make_unique<nugget::GameObject>();
	m_objects["Hello"] = std::move(text);

	auto textComp = m_objects["Hello"]->addComponent<nugget::renderComponent_Text>();
	textComp->setText("Tetris");

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Start();
	}
}

void Tetris::Update(float dt) {

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Update(dt);
	}
}

void Tetris::Render() {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		if (auto renderable = it->second->getSubComponent<nugget::Renderable>()) {
			renderable->Render();
		}
	}
}