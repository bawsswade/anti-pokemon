#include "MathLibrary.h"

Vector2D Vector2D::operator+(Vector2D &other)
{
	Vector2D temp;
	temp.x = x + other.x;
	temp.y = y + other.y;
	return temp;
}

Vector2D Vector2D::operator-(Vector2D &other)
{
	Vector2D temp;
	temp.x = x - other.x;
	temp.y = y - other.y;
	return temp;
}

Vector2D Vector2D::operator*(Vector2D &other)
{
	Vector2D temp;
	temp.x = x * other.x;
	temp.y = y * other.y;
	return temp;
}

Vector2D Vector2D::operator/(Vector2D &other)
{
	Vector2D temp;
	temp.x = x / other.x;
	temp.y = y / other.y;
	return temp;
}

void Vector2D::operator+=(Vector2D &other)
{
	x = x + other.x;
	y = y + other.y;
}

void Vector2D::operator-=(Vector2D &other)
{
	x = x - other.x;
	y = y - other.y;
}

void Vector2D::operator*=(Vector2D &other)
{
	x = x * other.x;
	y = y * other.y;
}

void Vector2D::operator/=(Vector2D &other)
{
	x = x / other.x;
	y = y / other.y;
}

void Vector2D::operator=(Vector2D &other)
{
	x = other.x;
	y = other.y;
}

bool Vector2D::operator==(Vector2D &other)
{
	return x == other.x && y == other.y;
}

Vector2D Normalize(Vector2D v)
{
	Vector2D temp;
	temp.x = v.x / Magnitude(v);
	temp.y = v.y / Magnitude(v);
	return temp;
}

Vector2D Normalize(float a_x, float a_y, float a_z)
{

}

float Magnitude(Vector2D v)
{
	float c = sqrt((v.x * v.x) + (v.y * v.y));
	return c;
}

