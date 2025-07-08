#include "Block.h"
#include "Components.h"
#include <iostream>

Block::Block() {
	
}

Block::~Block() {

}

void Block::Start() {
	std::vector<int> keys = {nugget::KEY_A, nugget::KEY_W, nugget::KEY_S, nugget::KEY_D};
	auto test = addComponent<nugget::inputComponent>();
	test->setKeys(keys);

	nugget::GameObject::Start();
}

void Block::Update(float dt) {
	nugget::GameObject::Update(dt);

	std::vector<int> keys;
	if (auto inputs = getComponent<nugget::inputComponent>()) {
		keys = inputs->getKeys();
	}

	for (int key : keys) {
		switch (key)
		{
		case nugget::KEY_A:
			std::cout << "A" << std::endl;
			break;
		case nugget::KEY_D:
			std::cout << "D" << std::endl;
			break;
		case nugget::KEY_W:
			std::cout << "W" << std::endl;
			break;
		case nugget::KEY_S:
			std::cout << "S" << std::endl;
			break;
		case nugget::KEY_NULL:
			std::cout << "none" << std::endl;
			break;
		default:
			break;
		}
	}
}