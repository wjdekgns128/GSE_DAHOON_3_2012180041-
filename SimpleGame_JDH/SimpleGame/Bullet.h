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
	//이 부분 수정
		dietimer = 0.0f;
		moveVector = GetMinDisByMaskObjects(4,
			PRIORITY(OBJECTTYPE::CHARACHTER_DEFENSE, 1.0f),
			PRIORITY(OBJECTTYPE::CHARACHTER, 2.2f), 
			PRIORITY(OBJECTTYPE::CHARACHTER_ARROW, 2.7f), 
			PRIORITY(OBJECTTYPE::BUILDING, 2.5f));

		moveVector = (moveVector -vec );
		moveVector.Nomalizing();

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