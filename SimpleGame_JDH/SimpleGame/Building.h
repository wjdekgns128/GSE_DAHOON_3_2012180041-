#pragma once
#include <stdio.h>
#include "BaseObject.h"
#include "Bullet.h"
class Building : public BaseObject
{
private:
	float       createBulletTimer;
	Bullet*		pBullet[MAX_OBJECT__COUNT];
public:
	Building(OBJECTTYPE type,TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime) : BaseObject(type,tag,vec,color,size,life,lifetime,0)
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			pBullet[i] = NULL;
		createBulletTimer = 0.0f;
	}
	
	~Building()
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			SAFE_DELETE(pBullet[i]);
	}

public:
	Bullet** getBullets()
	{
		return pBullet;
	}
public:
	void Update(float timer);
	void Render(Renderer* p);
	void CollProcessing(BaseObject* p);

private:
	void CreateBullet();

};