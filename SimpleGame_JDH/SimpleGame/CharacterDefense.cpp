#include "stdafx.h"
#include "CharacterDefense.h"
void CharacterDefense::Update(float timer)
{
	if (state != 1)
		return;
	CreateArrowTimer += timer;
	dietimer += timer;
	if (CreateArrowTimer > CREATEDEFENSEARROW)
	{
		CreateArrow();
	}
	if (dietimer >= lifetime)
	{
		state = 2;
	}
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] != NULL)
		{
			pArrow[i]->Update(timer);
		}
	}
	PlayAnimator(timer);
	
}
void CharacterDefense::PlayAnimator(float timer)
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
void CharacterDefense::Render(Renderer* p)
{
	if (state != 1)
		return;
	float NowHpBar = life / 250.0f;
	p->DrawTexturedRectSeq(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a, TexID,
		NowX, NowY, 6, 2, LEVEL_CHARACTER);
	p->DrawSolidRectGauge(vec.x, vec.y + 20, vec.z, 30, 6, HpBarColor.r, HpBarColor.g, HpBarColor.b, HpBarColor.a, NowHpBar, LEVEL_UI);
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] != NULL)
			pArrow[i]->Render(p);
	}

}
void CharacterDefense::CreateArrow()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pArrow[i] == NULL)
		{
			pArrow[i] = new Arrow(OBJECTTYPE::ARROW_DEFENS, tag, vec, MyColor(1,0,0.5f,1), 10.0f, 99999.0F, 99999999.0f, 1000.0f);
			CreateArrowTimer = 0.0f;
			break;
		}
	}
}

void CharacterDefense::CollProcessing(BaseObject* p)
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


