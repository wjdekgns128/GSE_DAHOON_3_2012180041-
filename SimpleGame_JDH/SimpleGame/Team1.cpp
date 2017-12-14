#include "stdafx.h"
#include "Team1.h"
#include "ObjectMgr.h"
void Team1::Update(float ElapsedTime)
{
	ObjectMgr::getinstance().pushteamObjects(pObject, tag);

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
	FindCreateObjectType();
	selectTimer += ElapsedTime;
	if (selectTimer > 0.3f)
	{
		selectScale == 1 ? selectScale = -1 : selectScale = 1;
		selectTimer = 0.0f;
	}
	if (TeamTimer > createTimer[CreateKeyType])
	{
		CreateCharacter();
		TeamTimer = 0.0f;
		for (int i = 0; i < 3; ++i)
			selectR_Color[i] = 0.0f;
		selectR_Color[CreateKeyType] = 1.0f;
	}
}
void Team1::FindCreateObjectType()
{
	int cCount = 0;
	int aCount = 0;
	int dCount = 0;
	BaseObject** o = ObjectMgr::getinstance().pullteamObjects(TEAMTAG::TEAM_2);
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (o[i] != NULL)
		{
			Character* P1 = dynamic_cast<Character*>(o[i]);
			CharacterArrow* P2 = dynamic_cast<CharacterArrow*>(o[i]);
			CharacterDefense* P3 = dynamic_cast<CharacterDefense*>(o[i]);
			if (P1 != NULL)
				cCount++;
			else if (P2 != NULL)
				aCount++;
			else if (P3 != NULL)
				dCount++;
		}
	}
	int percentage = rand() % 100;
	if (cCount == aCount && cCount == dCount)
	{
		CreateKeyType = 1;
		if (percentage <= 30)
			CreateKeyType = 0;
		else if (percentage >= 70)
			CreateKeyType = 2;

		
		return;
	}

	int TempCount = max(cCount, max(aCount, dCount));

	if (TempCount == cCount)
	{
		CreateKeyType = 2;
		if(percentage <= 30)
			CreateKeyType = 1;

	}
	else if (TempCount == aCount)
	{
		CreateKeyType = 1;
		if (percentage <= 30)
			CreateKeyType = 0;
	}
	else if (TempCount == dCount)
	{
		CreateKeyType = 1;
		if (percentage <= 30)
			CreateKeyType = 2;
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
			switch (CreateKeyType)
			{
			case 0:
				pObject[i] = new Character(OBJECTTYPE::CHARACHTER, tag, MyVector(x, y, 0), MyColor(1, 1, 1, 1), 40.0f, 150.0f, 9999999.0f, 35.0f);
				return;
			case 1:
				pObject[i] = new CharacterArrow(OBJECTTYPE::CHARACHTER_ARROW, tag, MyVector(x, y, 0), MyColor(1, 1, 1, 1), 40.0f, 300.0f, 9999999.0f, 5.0f);
				return;
			case 2:
				pObject[i] = new CharacterDefense(OBJECTTYPE::CHARACHTER_DEFENSE, tag, MyVector(x, y, 0), MyColor(1, 1, 1, 1), 40.0f, 250.0f, 99999999.0f, 0.0f);
				return;
			}
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
	int t = (TeamTimer / createTimer[0]);
	int t1 = (TeamTimer / createTimer[1]);
	int t2 = (TeamTimer / createTimer[2]);

	p->DrawSolidRectGauge(-225, 375, 30, 50 + (t * selectScale  * 1.5f), 50 + (t * selectScale *1.5f), selectR_Color[0], 0, 1, 1, ((TeamTimer / createTimer[0])), LEVEL_UI + 0.3f);
	p->DrawSolidRectGauge(-170, 375, 30, 50 + (t1 * selectScale * 1.5f), 50 + (t1 * selectScale *1.5f), selectR_Color[1], 0, 1, 1, ((TeamTimer / createTimer[1])), LEVEL_UI + 0.2f);
	p->DrawSolidRectGauge(-115, 375, 30, 50 + (t2 * selectScale * 1.5f), 50 + (t2 * selectScale * 1.5f), selectR_Color[2], 0, 1, 1, ((TeamTimer / createTimer[2])), LEVEL_UI + 0.2f);
}

