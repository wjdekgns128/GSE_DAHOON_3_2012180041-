#pragma once
#include <stdio.h>
#include "BaseObject.h"
#include "ObjectMgr.h"
class Bullet : public BaseObject
{
private:
	MyVector moveVector;
	float	 ParticleTime;
public:
	Bullet(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime,float speed) : BaseObject(type, tag, vec, color, size, life, lifetime,speed)
	{
		ParticleTime = 0.0f;
		float y;
		tag == TEAMTAG::TEAM_1 ?  y = -1.0f : y = 1.0f;
		moveVector.Setting(0, y, 0);
		moveVector.Nomalizing();
		dietimer = 0.0f;
	}

	~Bullet()
	{

	}

public:

public:
	void Update(float timer);
	void Render(Renderer* p);
	void CollProcessing(BaseObject* p);

private:

};