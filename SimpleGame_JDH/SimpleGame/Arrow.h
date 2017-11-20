#pragma once
#include <stdio.h>
#include "BaseObject.h"
class Arrow : public BaseObject
{
private:
	MyVector moveVector;
public:
	Arrow(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime, float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		float y = (rand() % 500);
		tag == TEAMTAG::TEAM_1 ? y *= -1 : y = y;
		moveVector.Setting(rand() % 100, y, 0);
		moveVector.Nomalizing();
		dietimer = 0.0f;
	}

	~Arrow()
	{

	}

public:

public:
	void Update(float timer);
	void Render(Renderer* p);
	void CollProcessing(BaseObject* p);

private:

};