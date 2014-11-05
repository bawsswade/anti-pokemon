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

	Vector2D operator/(Vector2D &other);

	void operator+=(Vector2D &other);

	void operator-=(Vector2D &other);

	void operator*=(Vector2D &other);

	void operator/=(Vector2D &other);

	void operator=(Vector2D &other);

	bool operator==(Vector2D &other);

	//Maths
	Vector2D Normalize(Vector2D v);

	Vector2D Normalize(float a_x, float a_y, float a_z);
//private:
	float x, y;
};





class Vector3D
{
public:
	//OVERLOAD OPERATORS
	Vector3D operator+(Vector3D &other);

	Vector3D operator-(Vector3D &other);

	Vector3D operator*(Vector3D &other);

	Vector3D operator/(Vector3D &other);

	void operator+=(Vector3D &other);

	void operator-=(Vector3D &other);

	void operator*=(Vector3D &other);

	void operator/=(Vector3D &other);

	void operator=(Vector3D &other);

	bool operator==(Vector3D &other);

	//Maths
	Vector3D Normalize(Vector3D v);

	Vector3D Normalize(float a_x, float a_y, float a_z);
	//private:
	float x, y, z;
};

// aka gets hypotonuese
float Magnitude(Vector2D v);
float Magnitude(float x, float y);

#endif