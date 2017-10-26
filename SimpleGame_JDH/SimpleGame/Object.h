#pragma once
#include <stdio.h>
#include "BaseObject.h"
class Object : public BaseObject
{
private:
	float tempx;
	float tempy;
	float			size;
	float saveTime;
public:
	Object(MyVector v, float size, float r, float g, float b, float a, float Speed) : BaseObject(v, r, g, b, a, Speed)
	{
		this->size = size;
		tempx = (( 5+ (rand() % 10) ) - 10) * 0.1f;
		 tempy =( ( 5 +(rand() % 10)) - 10) * 0.1f;
		 life = 10;
		 lifeTime = (rand()%1000000 + 1000000) * 0.001f;
		 state = 1; // ��������
		 saveTime = 0.0;
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
	float getSize()
	{
		return size;
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

public:
	void Update(DWORD timer);
	void Render(Renderer* p);


	// �浹 ������ ó��

	void CollByObject(float down);

};