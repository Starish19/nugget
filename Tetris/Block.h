#pragma once
#include "BaseGameObject.h"

class Block : public nugget::GameObject
{
public:
	Block();
	~Block();

	void Start() final;
	void Update(float dt) final ;
};

