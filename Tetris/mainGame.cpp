#include "mainGame.h"
#include "TetrisComp.h"

mainGame::mainGame(nugget::NuggetApplicazione* app) : nugget::NuggetScene(app) {}

void mainGame::Start() {
	nugget::nugResource->LoadImage("mudkip", "assets", "assets/images/mudkip.png");
	nugget::nugResource->LoadImage(Z_COLOR, "assets", "assets/images/RedRubix.png");
	nugget::nugResource->LoadImage(J_COLOR, "assets", "assets/images/BlueRubix.png");
	nugget::nugResource->LoadImage(I_COLOR, "assets", "assets/images/CyanRubix.png");
	nugget::nugResource->LoadImage(S_COLOR, "assets", "assets/images/GreenRubix.png");
	nugget::nugResource->LoadImage(O_COLOR, "assets", "assets/images/YellowRubix.png");
	nugget::nugResource->LoadImage(L_COLOR, "assets", "assets/images/OrangeRubix.png");
	nugget::nugResource->LoadImage(T_COLOR, "assets", "assets/images/PurpleRubix.png");

	nugget::nugResource->LoadWave("yipee", "assets", "assets/audio/yipee.mp3");

	nugget::nugResource->LoadMusic("agent_squidge", "assets", "assets/audio/Agent_Squidge.mp3");
	nugget::nugAudio->StartMusic(nugget::nugResource->getMusic("agent_squidge"));

	std::unique_ptr<nugget::GameObject> text = std::make_unique<nugget::GameObject>();
	m_objects["Hello"] = std::move(text);

	auto textComp = m_objects["Hello"]->addComponent<nugget::renderComponent_Text>();
	textComp->setText("Tetris");

	std::unique_ptr<nugget::GameObject> pauseMenu = std::make_unique<nugget::GameObject>();
	m_objects["pause"] = std::move(pauseMenu);
	auto renderComp = m_objects["pause"]->addComponent<nugget::renderComponent_Rect>();
	renderComp->setRect(nugget::Rectangle{0,0, nugget::nugRender->getWidth(), nugget::nugRender->getHeight()});
	renderComp->setColor(nugget::Color{ 200,200,200,150 });
	renderComp->render = false;

	activeBlock = newBlock();

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Start();
	}
}

void mainGame::Update(float dt) {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Update(dt);
	}

	if (auto TetrisComp = activeBlock->getComponent<renderComponent_Grid_Shape>()) {
		if (TetrisComp->checkGround() || blockCollision({0,1})) {
			activeBlock->active = false;
			activeBlock = newBlock();
			activeBlock->Start();
		}
	}  

	if (nugget::nugInput->KeyPressed(nugget::KEY_P)) {
		for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
			it->second->active = pauseToggle;
		}
		pauseToggle = !pauseToggle;
	}
}

void mainGame::Render() {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		if (auto renderable = it->second->getSubComponent<nugget::Renderable>()) {
			if (renderable->render) renderable->Render();
		}
	}

	if (pauseToggle) {
		m_objects["pause"]->getSubComponent<nugget::Renderable>()->Render();
	}

}

void mainGame::Close() {

}

Block* mainGame::newBlock() {
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

bool mainGame::blockCollision(nugget::coords at) {
	if (auto TetrisComp = activeBlock->getComponent<renderComponent_Grid_Shape>()) {
		for (int i = 0; i < BlockCount; i++) {
			if (auto check = m_objects["Block" + std::to_string(i)]->getComponent<renderComponent_Grid_Shape>()) {
				if (TetrisComp->checkCollision(check->getMinos(), at) && TetrisComp != check) {
					return true;
				}
			}
		}
	}
	return false;
}