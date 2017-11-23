#include "stdafx.h"
#include "Arrow.h"

void Arrow::Update(float timer)
{
	if (state != 1)
		return;
	dietimer += timer;
	vec += (moveVector * timer * speed);
	if (vec.x <= -250 + size / 2 || vec.x >= 250 - size / 2)
	{
		state = 2;
	}
	if (vec.y <= -400 + size / 2 || vec.y >= 400 - size / 2)
	{
		state = 2;
	}
	if (dietimer >= lifetime)
	{
		state = 2;
	}
}
void Arrow::Render(Renderer* p)
{
	if (state != 1)
		return;
	p->DrawSolidRect(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a, LEVEL_ARROW);
}

void Arrow::CollProcessing(BaseObject* p)
{
	switch (p->getType())
	{
	case OBJECTTYPE::BUILDING:
	case OBJECTTYPE::CHARACHTER:
		printf("arrow ªË¡¶\n");

		state = 2;
		break;
	}
}





