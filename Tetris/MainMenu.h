#pragma once
#include "nugget.h"

class MainMenu : public nugget::NuggetScene {
public:
	MainMenu(nugget::NuggetApplicazione* app);

	void Start() final;
	void Update(float dt) final;
	void Render() final;
	void Close() final;

private:
};