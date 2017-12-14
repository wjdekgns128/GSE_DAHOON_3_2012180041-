#pragma once
#include <stdio.h>
#include "BaseObject.h"
// ÃÖ¿ì¼±À¸·Î ÃÑ - > µðÆæ´õ
class Arrow : public BaseObject
{
private:

	MyVector moveVector;
public:
	Arrow(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime, float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		if (type == OBJECTTYPE::ARROW)
		{
			moveVector = GetMinDisByMaskObjects(2,
				PRIORITY(OBJECTTYPE::CHARACHTER_ARROW, 0.5f),
				PRIORITY(OBJECTTYPE::CHARACHTER_DEFENSE, 1.5f));
		}
		else if (type == OBJECTTYPE::ARROW_DEFENS)
		{
			moveVector = GetMinDisByMaskObjects(2,
				PRIORITY(OBJECTTYPE::CHARACHTER, 0.2f),
				PRIORITY(OBJECTTYPE::CHARACHTER_ARROW, 1.5f));
		}

		if (moveVector.x == -9999)
			state = 2;
		moveVector = (moveVector - vec);
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