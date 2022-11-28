#include "raylib.h"

class Player
{
	public:
		Vector3 pos;
		float vel;
		Texture2D tal;

		float getX();
		void setX(int x);

		float getY();
		void setY(int y);

		float getZ();
		void setZ(int z);

		void update(float delta);
		void draw(Camera camera);


		Player();
};
