#include <math.h>

#ifndef _MATH_LIBRARY_H_
#define _MATH_LIBRARY_H_

class Vector2D
{
public:
	//OVERLOAD OPERATORS
	Vector2D operator+(Vector2D &other);

	Vector2D operator-(Vector2D &other);

	Vector2D operator*(Vector2D &other);

	Vector2D operator=(Vector2D &other);

	Vector2D operator/(Vector2D &other);

	//Maths
	Vector2D Normalize(float a_x, float a_y);

	Vector2D Normalize(float a_x, float a_y, float a_z);

private:
	float x, y;
};



float Magnitude(float a, float b);

#endif