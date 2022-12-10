#include "raylib.h"

class Player
{
	public:
		Vector3 pos;
		float vel;
		float rotX; // 0 to 360
		float rotY; // 0.01 to 180

		float getRotX();
		void setRotX(float x);

		float getRotY();
		void setRotY(float y);

		float getX();
		void setX(int x);

		float getY();
		void setY(int y);

		float getZ();
		void setZ(int z);

		Vector3 getCamTarget();

		void update(float delta);
		void draw(Camera camera);

		Player();
};
