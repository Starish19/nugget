#include "stdafx.h"
#include "nugget.h"
#include "raylib.h"

using namespace nugget;

int main() {
	nugRender->Initalize();
	nugRender->setWindowParams(600, 600, "Nugget Engine");
	nugRender->setClear(BLUE);
	SetWindowIcon(LoadImage("assets/images/mudkip.png"));

	nugAudio->Initalize();
	SetMasterVolume(0.5);
	SetTargetFPS(30);

	nugResource->Initalize();
	nugInput->Initalize();

	nugget::nugApp->Start();

	int x = 300, y = 300;
	float width = 100;

	while (!WindowShouldClose()) {

		nugget::nugApp->Update(GetFrameTime());

		nugget::nugRender->StartDrawing();

		nugget::nugApp->Render();

		nugget::nugRender->FinishDrawing();
	}

	nugAudio->Shutdown();
	nugRender->Shutdown();
	nugResource->Shutdown();
	nugInput->Shutdown();
}