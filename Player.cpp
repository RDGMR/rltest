#include "Player.h"

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

void Player::update(float delta)
{
	if (IsKeyPressed(KEY_B)) setX(3);
	if (IsKeyDown(KEY_RIGHT)) pos.x += vel*delta;
	if (IsKeyDown(KEY_LEFT)) pos.x -= vel*delta;
	if (IsKeyDown(KEY_UP)) pos.z -= vel*delta;
	if (IsKeyDown(KEY_DOWN)) pos.z += vel*delta;
}

void Player::draw(Camera camera)
{
	DrawBillboard(camera, tal, pos, 5, WHITE);
}

Player::Player()
{
	tal = LoadTexture("resources/tree.png");
	pos = { 0.0f, 0.0f, 0.0f };
	vel = 7.5f;
}
