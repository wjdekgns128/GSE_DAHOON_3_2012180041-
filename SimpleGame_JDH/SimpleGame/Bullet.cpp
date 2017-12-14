#include "stdafx.h"
#include "Bullet.h"
#include "TexturData.h"
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
	ParticleTime += timer;
}
void Bullet::Render(Renderer* p)
{
	if (state != 1)
		return;
	p->DrawSolidRect(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a, LEVEL_BULLET);
	p->DrawParticle(vec.x, vec.y, vec.z, size, 1,1,1,1,
		moveVector.x * -1 , moveVector.y * -1 ,
		TexturData::getinstance().getTextur(TEX_BULLET), ParticleTime,LEVEL_BULLET + 0.1f);
}


void Bullet::CollProcessing(BaseObject* p)
{
	switch (p->getType())
	{
	case OBJECTTYPE::BUILDING:
	case OBJECTTYPE::CHARACHTER:
	case OBJECTTYPE::CHARACHTER_ARROW:
	case OBJECTTYPE::CHARACHTER_DEFENSE:
		state = 2;

		break;
	}
}

