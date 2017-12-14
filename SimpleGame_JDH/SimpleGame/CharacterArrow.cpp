#include "stdafx.h"
#include "CharacterArrow.h"
void CharacterArrow::Update(float timer)
{
	if (state != 1)
		return;
	CreateArrowTimer += timer;
	dietimer += timer;
	vec += (moveVector * timer * speed);
	if (CreateArrowTimer > CREATEARROW)
	{
		CreateArrow();
	}
	if (dietimer >= lifetime)
	{
		state = 2;
	}
	PlayAnimator(timer);
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
}
void CharacterArrow::PlayAnimator(float timer)
{
	AnimatorTime += timer;
	if (AnimatorTime > 0.09f)
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
void CharacterArrow::Render(Renderer* p)
{
	if (state != 1)
		return;
	float NowHpBar = life / 300.f;
	p->DrawTexturedRectSeq(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a, TexID,
		NowX, NowY, 6, 2, LEVEL_CHARACTER);
	p->DrawSolidRectGauge(vec.x, vec.y + 20, vec.z, 30, 6, HpBarColor.r, HpBarColor.g, HpBarColor.b, HpBarColor.a, NowHpBar, LEVEL_UI);
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] != NULL)
			pArrow[i]->Render(p);
	}

}
void CharacterArrow::CreateArrow()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] == NULL)
		{
			pArrow[i] = new Arrow(OBJECTTYPE::ARROW, tag, vec, MyColor(0.0f,0.0f, 0.0f,1.0f), 7.0f, 40.0f, 99999999.0f, 750.0f);
			CreateArrowTimer = 0.0f;
			break;
		}
	}
}

void CharacterArrow::CollProcessing(BaseObject* p)
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


