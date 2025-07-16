#include "nugget.h"
#include "Tetris.h"
#include "mainGame.h"
#include "MainMenu.h"

Tetris TetrisApp;
nugget::NuggetApplicazione* nugget::nugApp = &TetrisApp;

void Tetris::Initalize() {
	nugget::nugResource->addFile("assets", "assets.zip");

	current_scene = addScene<MainMenu>("Menu");
	addScene<mainGame>("Main");

	current_scene->Start();
}

void Tetris::Update(float dt) {
	current_scene->Update(dt);
}

void Tetris::Render() {
	current_scene->Render();
}

void Tetris::Shutdown() {
}