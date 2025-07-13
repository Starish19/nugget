#include "nugget.h"
#include "Tetris.h"
#include "TetrisComp.h"
#include "BlockManager.h"
#include <iostream>

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Start() {
	std::unique_ptr<BlockManager> block = std::make_unique<BlockManager>(&map);
	m_objects["Block_0_0"] = std::move(block);

	activeBlock = newBlock();

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

	if (auto TetrisComp = activeBlock->getComponent<renderComponent_Grid_Shape>()) {
		if (TetrisComp->checkGround()) {
			activeBlock->active = false;
			activeBlock = newBlock();
			activeBlock->Start();
		}
	}
}

void Tetris::Render() {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		if (auto renderable = it->second->getSubComponent<nugget::Renderable>()) {
			renderable->Render();
		}
	}
}

Block* Tetris::newBlock() {
	std::unique_ptr<Block> newBlock;
	switch (nugget::nugRand->getRandom(I, Z)) {
	case I:
		newBlock = std::make_unique<Block>(&map, I_TETROMINO, I_COLOR);
		break;
	case J:
		newBlock = std::make_unique<Block>(&map, J_TETROMINO, J_COLOR);
		break;
	case L:
		newBlock = std::make_unique<Block>(&map, L_TETROMINO, L_COLOR);
		break;
	case O:
		newBlock = std::make_unique<Block>(&map, O_TETROMINO, O_COLOR);
		break;
	case S:
		newBlock = std::make_unique<Block>(&map, S_TETROMINO, S_COLOR);
		break;
	case T:
		newBlock = std::make_unique<Block>(&map, T_TETROMINO, T_COLOR);
		break;
	case Z:
		newBlock = std::make_unique<Block>(&map, Z_TETROMINO, Z_COLOR);
		break;
	default:
		break;
	}
	Block* b = newBlock.get();
	m_objects["Block" + std::to_string(BlockCount++)] = std::move(newBlock);
	return b;
}