#include "stdafx.h"
#include "nugget.h"
#include "raylib.h"

using namespace nugget;

int main() {
	nugRender->Initalize();
	nugRender->setWindowParams(600, 600, "Nugget Engine");
	SetWindowIcon(LoadImage("assets/images/mudkip.png"));

	nugAudio->Initalize();
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

	nugResource->Initalize();
	nugResource->addFile("images", "assets.zip");

	nugResource->LoadImage("mudkip", "images", "assets/images/mudkip.png");
	nugResource->LoadImage("argh", "images", "assets/images/th.jpg");
	nugResource->LoadImage("red", "images", "assets/images/RedRubix.png");
	Image* img = nugResource->getImage("red");
	Texture2D tex = LoadTextureFromImage(*img);

	Wave* wav = nugResource->LoadWave("yippee", "images", "assets/audio/yipee.mp3");
	Sound yipee = LoadSoundFromWave(*wav);

	Rectangle rect{ 250,250,50,50 };

	nugget::nugApp->Start();

	while (!WindowShouldClose()) {

		std::vector<int> keys = { nugget::KEY_A, nugget::KEY_W, nugget::KEY_S, nugget::KEY_D, nugget::KEY_NULL };
		nugInput->KeyList(keys);
		for (int key : keys) {
			switch (key)
			{
			case nugget::KEY_A:
				rect.x -= 100 * GetFrameTime(); break;
			case nugget::KEY_D:
				rect.x += 100 * GetFrameTime(); break;
			case nugget::KEY_W:
				rect.y -= 100 * GetFrameTime(); break;
			case nugget::KEY_S:
				rect.y += 100 * GetFrameTime(); break;
			default:
				break;
			}
		}

		nugget::nugApp->Update(GetFrameTime());

		nugget::nugRender->StartDrawing();

		nugget::nugApp->Render();

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