#include "Block.h"
#include "TetrisComp.h"

Block::Block(TetrisGrid* grid, nugget::coords origin) {
	m_grid = grid;
	m_origin = origin;
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
	renderComp->setTexture("red");
	renderComp->setGrid(m_grid);
	renderComp->m_pos = m_origin;
	renderComp->setShape(std::vector <nugget::coords>{{0, 0}, {1, 0}, {2, 0}, {0, 1}, {0, 2}});
	//m_grid->move(renderComp->m_pos);


	//Audio Component
	auto audioComp = addComponent<nugget::audioComponent>();
	audioComp->SetSound("yipee");


	//Delayed Events
	auto timeComp = addComponent<nugget::TimeKeep>();
	//Move Down every second
	timeComp->addTrigger([=]() {
		renderComp->m_pos.posY += 1;
		//if (m_grid->move(renderComp->m_pos))
			//renderComp->m_pos.posY -= 1;
		}, 1);
	//Move Left/right
	timeComp->addTrigger([=]() {
		std::vector<int> keys =  inputComp->getKeys();
		for (int key : keys) {
			switch (key)
			{
			case nugget::KEY_A:
				renderComp->m_pos.posX -= 1;
				//if (m_grid->move(renderComp->m_pos)) 
					//renderComp->m_pos.posX += 1;
				break;
			case nugget::KEY_D:
				renderComp->m_pos.posX += 1;
				//if (m_grid->move(renderComp->m_pos))
					//renderComp->m_pos.posX -= 1;
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
		m_origin = renderComp->m_pos;
		if (auto inputComp = getComponent<nugget::inputComponent>()) {
			if (inputComp->getKey(nugget::KEY_R)) {
				renderComp->m_pos.rotate90(renderComp->m_pos + m_origin);
			}
			if (inputComp->getKey(nugget::KEY_S))
				renderComp->m_pos.posY += 1;
		}
	}
}