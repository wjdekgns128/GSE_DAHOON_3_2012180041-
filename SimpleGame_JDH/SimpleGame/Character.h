#pragma once
#include <stdio.h>
#include "Arrow.h"
#include "BaseObject.h"
class Character : public BaseObject
{
private:
	float		waitMoveTimer;
	int       waitRandomTimer;
	float       createArrowTimer;
	MyVector moveVector;
	Arrow*		pArrow[MAX_OBJECT__COUNT];

public:
	Character(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyVector Target, MyColor color, float size, float life, float lifetime,float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		waitRandomTimer = rand() % 10 + 4;
		waitMoveTimer = 0.0f;
		printf("기달리는 시간 : %d\n", waitRandomTimer);

		moveVector = Target- vec;
		moveVector.Nomalizing();
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			pArrow[i] = NULL;
		createArrowTimer = 0.0f;
	}

	~Character()
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			SAFE_DELETE(pArrow[i]);
	}

public:
	Arrow** getArrows()
	{
		return pArrow;
	}
public:
	void Update(float timer);
	void Render(Renderer* p);
	virtual void CollProcessing(BaseObject* p);
private:
	void CreateArrow();

};