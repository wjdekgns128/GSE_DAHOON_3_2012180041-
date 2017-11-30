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
	createArrowTimer += timer;
	if (createArrowTimer >= 1.0f)
	{
		CreateArrow();
		createArrowTimer = 0.0f;
	}
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] != NULL)
		{
			pArrow[i]->Update(timer);
			if (pArrow[i]->getState() == 2)
			{
				SAFE_DELETE(pArrow[i]);
			}
		}
	}
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

	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] != NULL)
			pArrow[i]->Render(p);
	}
}

void Character::CreateArrow()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] == NULL)
		{
			MyColor t1(0.5, 0.2, 0.7, 1);
			MyColor t2(1, 1, 0, 1);
			MyColor temp;
			tag == TEAMTAG::TEAM_1 ? temp = t1 : temp = t2;

			pArrow[i] = new Arrow(OBJECTTYPE::ARROW, tag, vec, temp, 4, 10.0f, 999999, 100); // 크기가 너무작아서 5로 수정.
			break;
		}
	}
}

void Character::CollProcessing(BaseObject* p)
{
	switch (p->getType())
	{
	case OBJECTTYPE::BUILDING:
		printf("캐릭터삭제\n");
		state = 2;
		break;
	case OBJECTTYPE::ARROW:
	case OBJECTTYPE::BULLET:

		life -= p->getLife();
		if (life <= 0)
			state = 2;
		printf("캐릭터 남은 라이프 %f\n", life);

		break;
	}
}


