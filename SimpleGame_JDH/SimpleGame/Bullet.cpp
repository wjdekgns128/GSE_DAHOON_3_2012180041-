#include "stdafx.h"
#include "Bullet.h"
#include "TexturData.h"
void Bullet::Update(float timer)
{
	if (state != 1)
		return;
	dietimer += timer;
	vec += (moveVector * timer * 150);
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
	ParticleTime += timer;
}
void Bullet::Render(Renderer* p)
{
	if (state != 1)
		return;
	float tempy = tag == TEAMTAG::TEAM_1 ? -5 : 5;
	p->DrawSolidRect(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a, LEVEL_BULLET);
	p->DrawParticle(vec.x, vec.y - tempy, vec.z, size, 1,1,1,1, moveVector.x * -2, moveVector.y * -5,
		TexturData::getinstance().getTextur(TEX_BULLET), ParticleTime);
}


void Bullet::CollProcessing(BaseObject* p)
{
	switch (p->getType())
	{
	case OBJECTTYPE::BUILDING:
	case OBJECTTYPE::CHARACHTER:
		state = 2;
		printf("bullet ªË¡¶\n");

		break;
	}
}

