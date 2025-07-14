#include "MainMenu.h"

MainMenu::MainMenu(nugget::NuggetApplicazione* app) : NuggetScene(app) {}

void MainMenu::Start() {
	std::unique_ptr<nugget::GameObject> button = std::make_unique<nugget::GameObject>();
	m_objects["Start"] = std::move(button);

	nugget::coords buttonPos = { 200,200 };
	nugget::dimensions buttonDim = { 200,200 };

	auto InputComp = m_objects["Start"]->addComponent<nugget::inputComponent>();
	InputComp->addButton([=]() {m_app->switchScene("Main"); }, buttonPos, buttonDim);

	auto RenderComp = m_objects["Start"]->addComponent<nugget::renderComponent_Rect>();
	RenderComp->setRect(buttonPos.posX, buttonPos.posY, buttonDim.width, buttonDim.Height);
	RenderComp->setColor(200,200,200,255);

	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Start();
	}
}

void MainMenu::Update(float dt) {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Update(dt);
	}
}

void MainMenu::Render() {
	for (auto it = m_objects.begin(); it != m_objects.end(); it++) {
		if (auto renderable = it->second->getSubComponent<nugget::Renderable>()) {
			renderable->Render();
		}
	}
}

void MainMenu::Close() {

}
