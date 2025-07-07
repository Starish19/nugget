#include "stdafx.h"
#include "nugget.h"
#include "raylib.h"

int main() {
	nugget::nugRender->Initalize();
	nugget::nugRender->setWindowParams(600, 600, "Nugget Engine");
	SetWindowIcon(LoadImage("assets/images/mudkip.png"));

	nugget::nugAudio->Initalize();
	SetMasterVolume(0.5);
	SetTargetFPS(30);

	/*nugget::zipFile file("assets.zip");

	const int size = 13000;
	std::vector<std::vector<unsigned char>> buffers(2);
	buffers[0].resize(size);
	buffers[1].resize(size);


	int totalread = file.LoadData("assets/images/mudkip.png", buffers[0]);
	Image img = LoadImageFromMemory(".png", &buffers[0][0], totalread);
	Texture2D tex = LoadTextureFromImage(img);

	totalread = file.LoadData("assets/audio/yipee.mp3", buffers[1]);
	Wave wav = LoadWaveFromMemory(".mp3", &buffers[1][0], totalread);
	Sound yipee = LoadSoundFromWave(wav);*/

	nugget::nugResource->Initalize();
	nugget::nugResource->addFile("images", "assets.zip");

	nugget::nugResource->LoadImage("mudkip", "images", "assets/images/mudkip.png");
	nugget::nugResource->LoadImage("argh", "images", "assets/images/th.jpg");
	nugget::nugResource->LoadImage("red", "images", "assets/images/RedRubix.png");
	Image* img = nugget::nugResource->getImage("red");
	Texture2D tex = LoadTextureFromImage(*img);

	Wave* wav = nugget::nugResource->LoadAudio("yippee", "images", "assets/audio/yipee.mp3");
	Sound yipee = LoadSoundFromWave(*wav);

	Rectangle rect{ 250,250,50,50 };

	while (!WindowShouldClose()) {

		std::vector<int> keys = { KEY_A, KEY_W, KEY_S, KEY_D, KEY_NULL };
		nugget::nugInput->KeyList(keys);

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

		nugget::nugApp->Update(GetFrameTime());

		nugget::nugRender->StartDrawing();
		nugget::nugRender->Clear(BLUE);

		nugget::nugRender->Text("Hello World", 100, 500, 20, BLACK);

		nugget::nugRender->DrawRect(&tex, &rect);

		//DrawTexture(tex, 300, 300, WHITE);
		nugget::nugRender->FinishDrawing();

		nugget::nugAudio->PlayNoise(&yipee);
	}

	nugget::nugAudio->Shutdown();
	nugget::nugRender->Shutdown();
	nugget::nugResource->Shutdown();
}