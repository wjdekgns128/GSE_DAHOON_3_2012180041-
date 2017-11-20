#include "stdafx.h"
#include "Bullet.h"

#include "stdafx.h"
#include "Bullet.h"
void Bullet::Update(float timer)
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
void Bullet::Render(Renderer* p)
{
	if (state != 1)
		return;
	p->DrawSolidRect(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a);
}


void Bullet::CollProcessing(BaseObject* p)
{
	switch (p->getType())
	{
	case OBJECTTYPE::CHARACHTER:
		state = 2;
		printf("bullet ªË¡¶\n");

		break;
	}
}





