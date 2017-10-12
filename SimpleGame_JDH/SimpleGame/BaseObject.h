#pragma once
#include "MyVector.h"
#include "Renderer.h"
class  BaseObject
{
protected:
	MyVector vector;
	float r, g, b, a;
	float Speed;
public:
	BaseObject(MyVector v,  float r, float g, float b, float a,float Speed) : vector(v), r(r), g(g), b(b), a(a),Speed(Speed)
	{

	}
	BaseObject()
	{
		vector.clear();
		r = 0;
		g = 0;
		b = 0;
		a = 0;
	}
	virtual ~BaseObject()
	{

	}
	virtual void Update() = 0;
	virtual void Render(Renderer* p) = 0;
public:
#pragma region get,set
	void setVector(const MyVector& _v)
	{
		vector = _v;
	}
	MyVector getVector(MyVector& _v)  const
	{
		_v = vector;
	}
	MyVector getVector()  const
	{
		return vector;
	}
	void getSpeed(float& t) const
	{
		t = Speed;
	}
	float getSpeed()
	{
		return Speed;
	}
	void setSpeed(float _speed)
	{
		Speed = _speed;
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

#pragma endregion
};
