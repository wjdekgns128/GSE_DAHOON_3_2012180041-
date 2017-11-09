#pragma once
#include <stdio.h>
#include "BaseObject.h"
class Arrow : public BaseObject
{
private:
	MyVector Move;
	int		 HeroId;
public:
	Arrow(MyVector v, float size, float r, float g, float b, float a, float Speed,
		OBJECTTYPE type, float life,int HeroId) : BaseObject(v, r, g, b, a, Speed, type, life)
	{
		this->HeroId = HeroId;
		this->size = size;
		state = 1; // 생성상태
		float tempx = rand() % 500 - 250;
		float tempy = rand() % 500 - 250;
		MyVector temp;
		temp.Setting(tempx, tempy, 0);
		Move = v - temp;
		Move.Nomalizing();
	}

	Arrow()
	{
	}
	~Arrow()
	{

	}

public:
	int getHeroId() { return HeroId; }
public:
	void Update(DWORD timer);
	void Render(Renderer* p);
	void CollByObject(float down);



};