#include "Block.h"
#include "TetrisComp.h"

Block::Block(nugget::grid* grid, Tetromino minos, std::string c) : m_grid(grid), m_minos(minos), color(c){

}

Block::~Block() {

}

void Block::Start() {
	//Input Component
	std::vector<int> keys = {nugget::KEY_A, nugget::KEY_D, nugget::KEY_S, nugget::KEY_R};
	auto inputComp = addComponent<nugget::inputComponent>();
	inputComp->setKeys(keys);


	//Render Component
	auto renderComp = addComponent<renderComponent_Grid_Shape>();
	renderComp->setTexture(color);
	renderComp->setGrid(m_grid);
	renderComp->m_pos = nugget::coords{5,0};
	renderComp->setShape(m_minos);


	//Audio Component
	auto audioComp = addComponent<nugget::audioComponent>();
	audioComp->SetSound("yipee");


	//Delayed Events
	auto timeComp = addComponent<nugget::TimeKeep>();
	//Move Down every second
	timeComp->addTrigger([=]() {
		renderComp->move({ 0,1 });
		}, 1);
	//Move Left/right
	timeComp->addTrigger([=]() {
		std::vector<int> keys =  inputComp->getKeys();
		for (int key : keys) {
			switch (key)
			{
			case nugget::KEY_A:
				renderComp->move({-1,0});
				break;
			case nugget::KEY_D:
				renderComp->move({1,0});
				break;
			default:
				break;
			}
		}
		}, 0.4);

	nugget::GameObject::Start();
}

void Block::Update(float dt) {
	nugget::GameObject::Update(dt);

	if (auto renderComp = getComponent<renderComponent_Grid_Shape>()) {
		if (auto inputComp = getComponent<nugget::inputComponent>()) {
			if (inputComp->getKey(nugget::KEY_R)) {
				renderComp->rotate90();
			}
			if (inputComp->getKey(nugget::KEY_S))
				renderComp->move({0,1});
		}
	}
}