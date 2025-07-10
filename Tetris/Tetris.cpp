#include "nugget.h"
#include "Tetris.h"
#include "Block.h"
#include <iostream>

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {
	std::unique_ptr<Block>first_block = std::make_unique<Block>();
	m_objects["firstBlock"] = std::move(first_block);

	nugget::nugResource->addFile("assets", "assets.zip");

	nugget::nugResource->LoadImage("mudkip", "assets", "assets/images/mudkip.png");
	nugget::nugResource->LoadImage("argh", "assets", "assets/images/th.jpg");
	nugget::nugResource->LoadImage("red", "assets", "assets/images/RedRubix.png");
	nugget::nugResource->LoadImage("test", "assets", "assets/images/test.png");

	nugget::nugResource->LoadWave("yipee", "assets", "assets/audio/yipee.mp3");
	nugget::nugResource->getSoundFromWave("yipee");

	std::unique_ptr<nugget::GameObject> text = std::make_unique<nugget::GameObject>();
	m_objects["Hello"] = std::move(text);

	auto textComp = m_objects["Hello"]->addComponent<nugget::renderComponent_Text>();
	textComp->setText("Hello World");

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
		if (auto renderable = it->second->getSubComponent<nugget::Renderable>()) {
			renderable->Render();
		}
	}
}