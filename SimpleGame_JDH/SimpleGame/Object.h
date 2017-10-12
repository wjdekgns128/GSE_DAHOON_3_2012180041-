#pragma once
#include <stdio.h>
#include "BaseObject.h"
class Object : public BaseObject
{
private:
	float			size;
public:
	Object(MyVector v, float size, float r, float g, float b, float a, float Speed) : BaseObject(v, r, g, b, a, Speed)
	{
		this->size = size;
	}
	Object()
	{
		size = 1;
	}
	~Object()
	{

	}

public:
#pragma region get,set
	void getSize(float& _size)
	{
		_size = size;
	}
	void setSize(float _size)
	{
		size = _size;
	}
#pragma endregion

public:
	void Update();
	void Render(Renderer* p);

};