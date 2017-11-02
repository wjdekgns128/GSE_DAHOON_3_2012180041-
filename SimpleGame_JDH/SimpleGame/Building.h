#pragma once
#include <stdio.h>
#include "BaseObject.h"
#include "Bullet.h"
class Building : public BaseObject
{
private:
	Bullet*		pBullet[100];
	float		savetimer;
public:
	Building(MyVector v, float size, float r, float g, float b, float a, float Speed,
		OBJECTTYPE type, float life) : BaseObject(v, r, g, b, a, Speed, type,  life)
	{
		this->size = size;
		state = 1; // 생성상태
		for (int i = 0; i < 100; ++i)
			pBullet[i] = NULL;
		savetimer = 0.0f;
	}

	Building()
	{
	}
	~Building()
	{
		for (int i = 0; i < 100; ++i)
			SAFE_DELETE(pBullet[i]);
	}

public:

public:
	void Update(DWORD timer);
	void Render(Renderer* p);
	void CollByObject(float down);

private:
	void CreateBullet();

public:
	Bullet** getBullet()
	{
		return pBullet;
	}

};