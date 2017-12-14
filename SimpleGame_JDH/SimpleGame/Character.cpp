#include "stdafx.h"
#include "Character.h"
void Character::Update(float timer)
{
	if (state != 1)
		return;
	dietimer += timer;
	waitMoveTimer += timer;
	if (waitMoveTimer >= waitRandomTimer)
		vec += (moveVector * timer * speed);
	
	if (dietimer >= lifetime)
	{
		state = 2;
	}
	PlayAnimator(timer);
}
void Character::PlayAnimator(float timer)
{
	AnimatorTime += timer;
	if (AnimatorTime > 0.07f)
	{
		NowX++;
		if (NowX >= 6)
		{
			NowX = 0;
			NowY++;
			NowY %= 2;
		}
		AnimatorTime = 0.0;
	}
}
void Character::Render(Renderer* p)
{
	if (state != 1)
		return;
	float NowHpBar = life / 100.f;
	p->DrawTexturedRectSeq(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a, TexID,
		NowX, NowY, 6, 2,LEVEL_CHARACTER);
	p->DrawSolidRectGauge(vec.x, vec.y + 20, vec.z, 30, 6, HpBarColor.r, HpBarColor.g, HpBarColor.b, HpBarColor.a, NowHpBar, LEVEL_UI);


}

void Character::CollProcessing(BaseObject* p)
{
	switch (p->getType())
	{
	case OBJECTTYPE::BUILDING:
		state = 2;
		break;
	case OBJECTTYPE::ARROW:
	case OBJECTTYPE::BULLET:
	case OBJECTTYPE::ARROW_DEFENS:

		life -= p->getLife();
		if (life <= 0)
			state = 2;
		break;
	}
}


