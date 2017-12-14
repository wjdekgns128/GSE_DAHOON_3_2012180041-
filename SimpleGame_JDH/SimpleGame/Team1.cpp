#include "stdafx.h"
#include "Team1.h"

void Team1::Update(float ElapsedTime)
{

	TeamTimer += ElapsedTime;
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pObject[i] != NULL)
		{
			pObject[i]->Update(ElapsedTime);
			if (pObject[i]->getState() == 2)
			{
				SAFE_DELETE(pObject[i]);
			}
		}
	}
	if (TeamTimer > CREATECHARACHTER)
	{
		CreateCharacter();
		TeamTimer = 0.0f;
	}
}
void Team1::Render(Renderer* p)
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pObject[i] != NULL)
		{
			pObject[i]->Render(p);
		}
	}
	RenderSelect(p);
}
void Team1::CreateCharacter()
{
	int x = rand() % 481 - 240;
	int y = rand() % 220 + 20;
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pObject[i] == NULL)
		{
			pObject[i] = new Character(OBJECTTYPE::CHARACHTER, tag, MyVector(x, y, 0), MyColor(1, 1, 1, 1), 40, 100, 9999999, 50.0f);
			break;
		}

	}
}
void Team1::Mouse(int button, int state, int x, int y)
{

}
void Team1::Key(int key, int x, int y)
{

}
void Team1::RenderSelect(Renderer* p)
{
	p->DrawTexturedRectSeq(-225, 375, 0, 50, 1, 1, 1, 1, TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER),
		0, 0, 6, 2, LEVEL_UI + 0.15f);

	p->DrawTexturedRectSeq(-170, 375, 0, 50, 1, 1, 1, 1, TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER_ARROW),
		0, 0, 6, 2, LEVEL_UI + 0.15f);
	p->DrawTexturedRectSeq(-115, 375, 0, 50, 1, 1, 1, 1, TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER_DEFENSE),
		0, 0, 6, 2, LEVEL_UI + 0.15f);
	int t = (TeamTimer / CREATECHARACHTER);
	int t1 = (TeamTimer / CREATEARROWCHARACHTER);
	int t2 = (TeamTimer / CREATEDEFENSECHARACHTER);

	p->DrawSolidRectGauge(-225, 375, 30, 50 + (t * selectScale  * 1.5f), 50 + (t * selectScale *1.5f), selectR_Color[0], 0, 1, 1, ((TeamTimer / CREATECHARACHTER)), LEVEL_UI + 0.3f);
	p->DrawSolidRectGauge(-170, 375, 30, 50 + (t1 * selectScale * 1.5f), 50 + (t1 * selectScale *1.5f), selectR_Color[1], 0, 1, 1, ((TeamTimer / CREATEARROWCHARACHTER)), LEVEL_UI + 0.2f);
	p->DrawSolidRectGauge(-115, 375, 30, 50 + (t2 * selectScale * 1.5f), 50 + (t2 * selectScale * 1.5f), selectR_Color[2], 0, 1, 1, ((TeamTimer / CREATEDEFENSECHARACHTER)), LEVEL_UI + 0.2f);
}

