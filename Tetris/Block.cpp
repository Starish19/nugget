#include "Block.h"
#include "Components.h"
#include <iostream>

Block::Block(nugget::grid* grid) {
	m_grid = grid;
}

Block::~Block() {

}

void Block::Start() {
	std::vector<int> keys = {nugget::KEY_A, nugget::KEY_D, nugget::KEY_R};
	auto inputComp = addComponent<nugget::inputComponent>();
	inputComp->setKeys(keys);

	auto renderComp = addComponent<nugget::renderComponent_Grid>();
	renderComp->setTexture("red");
	renderComp->setGrid(m_grid);

	auto audioComp = addComponent<nugget::audioComponent>();
	audioComp->SetSound("yipee");

	auto timeComp = addComponent<nugget::TimeKeep>();
	timeComp->addTrigger([=]() {
		renderComp->m_column += 1;
		//renderComp->setRect(nugget::Y, renderComp->getRect(nugget::Y) + 25);
		}, 1);
	timeComp->addTrigger([=]() {
		std::vector<int> keys =  inputComp->getKeys();
		for (int key : keys) {
			switch (key)
			{
			case nugget::KEY_A:
				renderComp->m_row -= 1;
				//renderComp->setRect(nugget::X, renderComp->getRect(nugget::X) - 50);
				break;
			case nugget::KEY_D:
				renderComp->m_row += 1;
				//renderComp->setRect(nugget::X, renderComp->getRect(nugget::X) + 50);
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

	if (auto renderComp = getComponent<nugget::renderComponent_Grid>())
	if (auto inputComp = getComponent<nugget::inputComponent>()) {
		if (inputComp->getKey(nugget::KEY_R))
			renderComp->Rotate90({ renderComp->m_row - 1, renderComp->m_column - 2 });
	}
}