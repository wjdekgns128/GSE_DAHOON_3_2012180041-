#pragma once
#include <stdio.h>
#include "BaseObject.h"
#include "Bullet.h"
#include "Arrow.h"
class Character : public BaseObject
{
private:
	Arrow*	pArrow[100];
	int  HeroId;
	float tempx;
	float tempy;
	float saveTime;
	float CreateTime;
public:
	Character(MyVector v, float size, float r, float g, float b, float a, float Speed,
		OBJECTTYPE type,float life,int HeroId) : BaseObject(v, r, g, b, a, Speed,type,life)
	{
		this->HeroId = HeroId;
		for (int i = 0; i < 100; ++i)
			pArrow[i] = NULL;
		this->size = size;
		tempx = (((5 + (rand() % 10)) - 10) * 0.1f) + 0.1f;
		tempy = (((5 + (rand() % 10)) - 10) * 0.1f) + 0.1f;
		 lifeTime = (rand()%1000000 + 1000000) * 0.001f;
		 state = 1; // 생성상태
		 saveTime = 0.0;
		 CreateTime = 0.0;
	}

	Character()
	{
		size = 1;
	}
	~Character()
	{
		for (int i = 0; i < 100; ++i)
			SAFE_DELETE(pArrow[i]);
	}

public:

	int getHeroId() { return HeroId; }

public:
	void Update(DWORD timer);
	void Render(Renderer* p);
	// 충돌 했을때 처리

	void CollByObject(float down);
	void CreateArrow();
	Arrow** getArrow()
	{
		return pArrow;
	}
};