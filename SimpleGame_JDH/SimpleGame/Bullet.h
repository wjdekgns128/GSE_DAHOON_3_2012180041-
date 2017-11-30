#pragma once
#include <stdio.h>
#include "BaseObject.h"
class Bullet : public BaseObject
{
private:
	MyVector moveVector;
	float	 ParticleTime;
public:
	Bullet(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime,float speed) : BaseObject(type, tag, vec, color, size, life, lifetime,speed)
	{
		ParticleTime = 0.0f;
		float y = (rand() % 500 );
		tag == TEAMTAG::TEAM_1 ? y *= -1 : y = y;
		moveVector.Setting(rand() % 10 - 5 , y, 0);
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