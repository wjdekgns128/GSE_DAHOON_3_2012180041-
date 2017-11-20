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
	if (createArrowTimer >= 3.0f)
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
}
void Character::Render(Renderer* p)
{
	if (state != 1)
		return;

	p->DrawSolidRect(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a);
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

			pArrow[i] = new Arrow(OBJECTTYPE::ARROW, tag, vec, temp, 5, 10.0f, 999999, 100);
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


