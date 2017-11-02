#pragma once
#include <stdio.h>
#include "BaseObject.h"
class Bullet : public BaseObject
{
private:
	MyVector Move;
public:
	Bullet(MyVector v, float size, float r, float g, float b, float a, float Speed,
		OBJECTTYPE type, float life) : BaseObject(v, r, g, b, a, Speed, type, life)
	{
		this->size = size;
		state = 1; // 생성상태
		float tempx = rand() % 500 - 250;
		float tempy = rand() % 500 - 250 ;
		MyVector temp;
		temp.Setting(tempx, tempy, 0);
		Move = v - temp;
		Move.Nomalizing();
	}

	Bullet()
	{
	}
	~Bullet()
	{

	}

public:

public:
	void Update(DWORD timer);
	void Render(Renderer* p);
	void CollByObject(float down);



};