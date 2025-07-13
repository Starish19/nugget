#include "nugget.h"
#include "Tetris.h"
#include "Block.h"
#include <iostream>
#include "BlockManager.h"

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {
	std::unique_ptr<Block> block = std::make_unique<Block>(&map, J_TETROMINO, J_COLOR);
	m_objects["Block_0_0"] = std::move(block);

	nugget::nugResource->addFile("assets", "assets.zip");

	nugget::nugResource->LoadImage("mudkip", "assets", "assets/images/mudkip.png");
	nugget::nugResource->LoadImage("argh", "assets", "assets/images/th.jpg");
	nugget::nugResource->LoadImage(Z_COLOR, "assets", "assets/images/RedRubix.png");
	nugget::nugResource->LoadImage(J_COLOR, "assets", "assets/images/BlueRubix.png");
	nugget::nugResource->LoadImage(I_COLOR, "assets", "assets/images/CyanRubix.png");
	nugget::nugResource->LoadImage(S_COLOR, "assets", "assets/images/GreenRubix.png");
	nugget::nugResource->LoadImage(O_COLOR, "assets", "assets/images/YellowRubix.png");
	nugget::nugResource->LoadImage(L_COLOR, "assets", "assets/images/OrangeRubix.png");
	nugget::nugResource->LoadImage(T_COLOR, "assets", "assets/images/PurpleRubix.png");

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