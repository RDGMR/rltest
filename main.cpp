#include "raylib.h"
#include "Player.cpp"

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "rltest");

	// Texture2D tree = LoadTexture("resources/tree.png");

	Camera camera;
	camera.position = { 0.0f, 10.0f, 10.0f };
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	bool debug = true;

	SetTargetFPS(144);

	Player player;

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();

		if (IsKeyPressed(KEY_V))
			debug = !debug;

		player.update(delta);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode3D(camera);
			DrawGrid(20, 1.0f);
			player.draw(camera);
		EndMode3D();

		if (debug)
		{
			DrawFPS(5, 5);
			DrawText(TextFormat("X %.2f", player.getX()), 5, 25, 20, LIME);
			DrawText(TextFormat("Y %.2f", player.getY()), 5, 45, 20, LIME);
			DrawText(TextFormat("Z %.2f", player.getZ()), 5, 65, 20, LIME);
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
