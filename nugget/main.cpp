#include "RenderSystemRaylib.h"

using namespace nugget;

int main() {
	nugRenderSystem->Initalize();
	nugRenderSystem->setWindowParams(600, 600, "Nugget Engine");
	SetWindowIcon(LoadImage("assets/images/mudkip.png"));
	
	InitAudioDevice();
	SetTargetFPS(60);

	Texture2D tex = LoadTexture("assets/images/mudkip.png");
	Sound yipee = LoadSound("assets/audio/yipee.mp3");

	Rectangle rect{ 250,250,250,100 };

	int key(0);

	while (!WindowShouldClose()) {

		if (IsKeyDown(KEY_A)) rect.x -= 100 * GetFrameTime();

		nugRenderSystem->StartDrawing();
		nugRenderSystem->Clear(BLUE);
		
		//SetShapesTexture(tex, Rectangle{0,0, (float)tex.width, (float)tex.height });

		//DrawPoly(Vector2{ 150,150 }, 6, 100, 0, WHITE);

		//DrawCircle(300,50, 100, WHITE);

		//DrawRectangleRec(Rectangle{position.x,250,250,100 }, WHITE);

		//nugRenderSystemRL->DrawRect(&tex, &rect);

		nugRenderSystem->Text("Hello World", 100, 500, 20, BLACK);

		nugRenderSystem->DrawRect(&tex, &rect);

		//DrawTexture(tex, 300, 300, WHITE);
		nugRenderSystem->FinishDrawing();

		if (!IsSoundPlaying(yipee)) PlaySound(yipee);
	}

	UnloadTexture(tex);
	UnloadSound(yipee);

	CloseAudioDevice();
	nugRenderSystem->Shutdown();
}