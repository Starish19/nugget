#include "RenderSystemRaylib.h"
#include "AudioSystemRaylib.h"
#include "InputSystemRaylib.h"

using namespace nugget;

int main() {
	nugRender->Initalize();
	nugRender->setWindowParams(600, 600, "Nugget Engine");
	SetWindowIcon(LoadImage("assets/images/mudkip.png"));

	nugAudio->Initalize();
	SetMasterVolume(0.5);
	SetTargetFPS(60);

	Texture2D tex = LoadTexture("assets/images/mudkip.png");
	Sound yipee = LoadSound("assets/audio/yipee.mp3");

	Rectangle rect{ 250,250,250,100 };

	while (!WindowShouldClose()) {

		int keys[5] = { KEY_A, KEY_W, KEY_S, KEY_D, KEY_NULL };
		nugInput->KeyList(keys);

		for (int key : keys) {
			switch (key)
			{
			case KEY_A:
				rect.x -= 100 * GetFrameTime(); break;
			case KEY_D:
				rect.x += 100 * GetFrameTime(); break;
			case KEY_W:
				rect.y -= 100 * GetFrameTime(); break;
			case KEY_S:
				rect.y += 100 * GetFrameTime(); break;
			default:
				break;
			}
		}

		nugRender->StartDrawing();
		nugRender->Clear(BLUE);

		nugRender->Text("Hello World", 100, 500, 20, BLACK);

		nugRender->DrawRect(&tex, &rect);

		//DrawTexture(tex, 300, 300, WHITE);
		nugRender->FinishDrawing();

		nugAudio->PlayNoise(&yipee);
	}

	UnloadTexture(tex);
	UnloadSound(yipee);

	nugAudio->Shutdown();
	nugRender->Shutdown();
}