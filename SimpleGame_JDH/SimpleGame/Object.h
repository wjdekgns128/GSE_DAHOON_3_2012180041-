#pragma once
#include <stdio.h>
#include "MyVector.h"
class Object
{
private:
	float			size;
	MyVector vector;
	float r, g, b, a;
public:
	Object(MyVector v,float size, float r , float g , float b , float a ) : vector(v),r(r),g(g),b(b),a(a),size(size)
	{
		
	}
	Object()
	{
		vector.clear();
		r = 0;
		g = 0;
		b = 0;
		a = 0;
		size = 1;
	}
	virtual ~Object()
	{

	}

public:
	virtual void TestDebugLog() // 추후에 테스트을 위한
	{
		printf("x , y , z ,size : %f %f %f %f\n", vector.x, vector.y, vector.z,size);
	}
public:
#pragma region get,set

	void getVector(MyVector& _v)  const
	{
		_v = vector;
	}
	void setVector(const MyVector& _v)
	{
		vector = _v;
	}
	void setVector(float x, float y, float z)
	{
		vector.Setting(x, y, z);
	}
	void getRGBA(float& _r, float& _g, float& _b, float& _a) const
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}
	void setRGBA(float _r, float _g, float _b, float _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}
	void getSize(float& _size)
	{
		_size = size;
	}
	void setSize(float _size)
	{
		size = _size;
	}
#pragma endregion

};