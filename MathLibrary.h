#include <math.h>

#ifndef _MATH_LIBRARY_H_
#define _MATH_LIBRARY_H_

class Vector2D
{
public:
	Vector2D();
	Vector2D(float a_x, float a_y);
	~Vector2D();

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
	void Scale(Vector2D v, float num);
	float GetAngle(Vector2D a, Vector2D b);

//private:
	float x, y;

private:
	// normalize vector (get hypotnuse to 1)
	Vector2D Normalize(Vector2D v);

	// return scalar of vector b projected onto vector a
	float DotProduct(Vector2D a, Vector2D b);

	// returns perp vector
	Vector2D Perp(Vector2D v);
};





class Vector3D
{
public:
	Vector3D();
	Vector3D(float a_x, float a_y, float a_z);
	~Vector3D();

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

	void Scale(Vector3D v, float num);

	// return scalar of vector b projected onto vector a
	float DotProduct(Vector3D a, Vector3D b);

	//private:
	float x, y, z;
};

// aka gets hypotonuese
float Magnitude(Vector2D v);
float Magnitude(float x, float y);

#endif