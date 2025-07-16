#include "stdafx.h"
#include "nugget.h"
#include "raylib.h"

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
	nugRender->setWindowIcon(nullptr);
	nugRender->setFPS(app_defaults.frameRate);
	
	nugAudio->setMasterVolume(app_defaults.MasterVolume);

	int frame = 0;
	while (!nugRender->closeWindow()) {
		nugApp->Update(nugRender->getDeltaTime());

		nugAudio->UpdateMusic();

		nugRender->StartDrawing();

		nugApp->Render();

		nugRender->FinishDrawing();
	}

	nugAudio->Shutdown();
	nugRender->Shutdown();
	nugResource->Shutdown();
	nugInput->Shutdown();
	nugApp->Shutdown();
}