#include "Player.h"
#include <cmath>

float Player::getRotX()
{
	return rotX;
}
void Player::setRotX(float x)
{
	rotX = x;
}

float Player::getRotY()
{
	return rotY;
}
void Player::setRotY(float y)
{
	rotY = y;
}

float Player::getX()
{
	return pos.x;
}
void Player::setX(int x)
{
	pos.x = x;
}

float Player::getY()
{
	return pos.y;
}
void Player::setY(int y)
{
	pos.y = y;
}

float Player::getZ()
{
	return pos.z;
}
void Player::setZ(int z)
{
	pos.z = z;
}

Vector3 Player::getCamTarget()
{
	float xVal = std::cos(rotX * 3.14159 / 180) * std::sin(rotY * 3.14159 / 180);
	float yVal = std::cos(rotY * 3.14159 / 180);
	float zVal = std::sin(rotX * 3.14159 / 180) * std::sin(rotY * 3.14159 / 180);
	Vector3 target = {
		pos.x + xVal,
		pos.y + yVal,
		pos.z + zVal
		};
	return target;
}

void Player::update(float delta)
{
	Vector2 offset = GetMouseDelta();
	rotX += offset.x / 10;
	rotY += offset.y / 10;
	if (rotX > 360) rotX = 0;
	if (rotX < 0) rotX = 360;
	if (rotY > 180) rotY = 180;
	else if (rotY < 0.01) rotY = 0.01;
	if (GetMouseX() != 400 || GetMouseY() != 225)
	{
		SetMousePosition(400, 225);
	}

	if (IsKeyPressed(KEY_R))
	{
		setX(0);
		setZ(0);
		rotX = 0;
		rotY = 0;
	}
	if (IsKeyDown(KEY_D))
	{
		int val = rotX + 90;
		pos.z += std::sin(val * 3.14159 / 180) * vel * delta;
		pos.x += std::cos(val * 3.14159 / 180) * vel * delta;
	}
	if (IsKeyDown(KEY_A))
	{
		int val = rotX - 90;
		pos.z += std::sin(val * 3.14159 / 180) * vel * delta;
		pos.x += std::cos(val * 3.14159 / 180) * vel * delta;
	}
	if (IsKeyDown(KEY_W))
	{
		pos.z += std::sin(rotX * 3.14159 / 180) * vel * delta;
		pos.x += std::cos(rotX * 3.14159 / 180) * vel * delta;
	} 
	if (IsKeyDown(KEY_S))
	{
		pos.z -= std::sin(rotX * 3.14159 / 180) * vel * delta;
		pos.x -= std::cos(rotX * 3.14159 / 180) * vel * delta;
	}

	if (IsKeyDown(KEY_SPACE)) pos.y += vel * delta / 3;
	if (IsKeyDown(KEY_LEFT_CONTROL)) pos.y -= vel*delta/3;
}

void Player::draw(Camera camera)
{
	// DrawBillboard(camera, tal, pos, 5, WHITE);
	// DrawCube(getCamTarget(), .1,.1,.1, RED);
}

Player::Player()
{
	pos = { 0.0f, 0.0f, 0.0f };
	vel = 7.5f;
	rotX = 90;
	rotY = 90;
}
