#pragma once
#include <math.h>

class MyVector
{
public:
	float x;
	float y;
	float z;
public:
	MyVector(float x, float y, float z) : x(x),y(y),z(z)
	{

	}
	MyVector()
	{
		x = y = z = 0;
	}

public:
	~MyVector()
	{

	}
public:
	void clear()
	{
		x = y = z = 0;
	}
	void Setting(float x, float y, float z)	{
		this->x = x;
		this->y = y;
		this->z = z;

	}
	void Nomalizing()
	{
		float len = VectorSize();

		this->x = x / len;
		this->y = y / len;
		this->z = z / len;

	}
	float VectorSize()
	{
		return sqrtf(x*x + y*y + z*z);
	}
#pragma region Vector operator
	
	MyVector operator+(const MyVector& m)
	{
		
		return MyVector(x+m.x, y+m.y, z+m.z);
	}
	MyVector operator*(const MyVector& m)
	{
		return MyVector(x * m.x, y * m.y, z * m.z);


	}
	MyVector operator*(const float m)
	{
	
		return MyVector(x * m, y * m, z * m);


	}
	MyVector operator-(const MyVector& m)
	{
		return MyVector(x - m.x, y - m.y, z - m.z);


	}
	MyVector& operator+=(const MyVector& m)
	{
		x += m.x;
		y += m.y;
		z += m.z;
		return *this;
	}
	MyVector& operator*=(const MyVector& m)
	{
		x *= m.x;
		y *= m.y;
		z *= m.z;
		return *this;

	}
	MyVector& operator-=(const MyVector& m)
	{
		x -= m.x;
		y -= m.y;
		z -= m.z;
		return *this;

	}
	MyVector& operator*=(const float& m)
	{
		x *= m;
		y *= m;
		z *= m;
		return *this;

	}
#pragma endregion

	


};