#include "RenderSystemRaylib.h"
#include "AudioSystemRaylib.h"
#include "InputSystemRaylib.h"

#include "unzip.h"
#include <vector>

using namespace nugget;

int main() {
	nugget::nugRender->Initalize();
	nugget::nugRender->setWindowParams(600, 600, "Nugget Engine");
	SetWindowIcon(LoadImage("assets/images/mudkip.png"));

	nugget::nugAudio->Initalize();
	SetMasterVolume(0.5);
	SetTargetFPS(60);

	unzFile ziphandle = unzOpen64("assets.zip");

	const int size = 1024 * 150;
	unsigned char buffers[3][size];

	int result = unzLocateFile(ziphandle, "assets/images/mudkip.png", 1);
	int totalread = 0;
	int read;
	if (result == UNZ_OK) {
		result = unzOpenCurrentFile(ziphandle);
		for (int i = 0; (read = unzReadCurrentFile(ziphandle, &(buffers[i][0]), size)) > 0; i++) {
			totalread += read;
		}
		unzCloseCurrentFile(ziphandle);
	}
	unzClose(ziphandle);

	/*buff[totalread] = '\0';
	printf("Test: ");
	printf(buff);
	printf("\n\n");*/

	Image img = LoadImageFromMemory(".png", &(buffers[0][0]), totalread);

	Texture2D tex = LoadTextureFromImage(img);

	//Texture2D tex = LoadTexture("assets/images/mudkip.png");
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

		nugget::nugRender->StartDrawing();
		nugget::nugRender->Clear(BLUE);

		nugget::nugRender->Text("Hello World", 100, 500, 20, BLACK);

		nugget::nugRender->DrawRect(&tex, &rect);

		//DrawTexture(tex, 300, 300, WHITE);
		nugget::nugRender->FinishDrawing();

		nugget::nugAudio->PlayNoise(&yipee);
	}

	UnloadTexture(tex);
	UnloadSound(yipee);

	nugget::nugAudio->Shutdown();
	nugget::nugRender->Shutdown();
}