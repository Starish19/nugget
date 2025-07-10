#include "Block.h"
#include "Components.h"
#include <iostream>

Block::Block() {
	
}

Block::~Block() {

}

void Block::Start() {
	std::vector<int> keys = {nugget::KEY_A, nugget::KEY_D};
	auto inputComp = addComponent<nugget::inputComponent>();
	inputComp->setKeys(keys);

	auto renderComp = addComponent<nugget::renderComponent_Rect>();
	renderComp->setTexture("red");
	renderComp->setRect(200, 200, 30, 30);

	auto audioComp = addComponent<nugget::audioComponent>();
	audioComp->SetSound("yipee");

	auto timeComp = addComponent<nugget::TimeKeep>();
	timeComp->addTrigger([=]() {
		renderComp->setRect(nugget::Y, renderComp->getRect(nugget::Y) + 25);
		}, 1);
	timeComp->addTrigger([=]() {
		std::vector<int> keys =  inputComp->getKeys();
		for (int key : keys) {
			switch (key)
			{
			case nugget::KEY_A:
				renderComp->setRect(nugget::X, renderComp->getRect(nugget::X) - 50);
				break;
			case nugget::KEY_D:
				renderComp->setRect(nugget::X, renderComp->getRect(nugget::X) + 50);
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

}