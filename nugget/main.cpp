#include "stdafx.h"
#include "nugget.h"
#include "raylib.h"

#include <iostream>

using namespace nugget;

int main() {
	nugResource->Initalize();
	nugInput->Initalize();
	nugRand->Initalize();
	nugRender->Initalize();
	nugAudio->Initalize();

	nugget::nugApp->Initalize();
	defaults app_defaults = nugApp->getDefaults();


	nugRender->setWindowParams(app_defaults.WindowWidth, app_defaults.WindowHeight, app_defaults.WindowName);
	nugRender->setClear(app_defaults.ClearColor);
	//SetWindowIcon(RAYLIB_H::LoadImage("assets/images/nugget.png"));
	
	SetMasterVolume(app_defaults.MasterVolume);
	SetTargetFPS(app_defaults.frameRate);

	Music* mus = nugget::nugResource->LoadMusic("agent_squidge", "assets", "assets/audio/Agent_Squidge.mp3");

	nugget::nugAudio->StartMusic(mus);

	int frame = 0;
	while (!WindowShouldClose()) {
		nugget::nugApp->Update(GetFrameTime());

		std::cout << frame++ << std::endl;

		UpdateMusicStream(*mus);

		nugget::nugRender->StartDrawing();

		nugget::nugApp->Render();

		nugget::nugRender->FinishDrawing();

		nugget::nugAudio->Resume();
	}

	nugAudio->Shutdown();
	nugRender->Shutdown();
	nugResource->Shutdown();
	nugInput->Shutdown();
	nugApp->Shutdown();
}