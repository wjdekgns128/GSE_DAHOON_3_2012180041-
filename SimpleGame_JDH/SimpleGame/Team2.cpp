#include "stdafx.h"
#include "Team2.h"
#include "Dependencies\freeglut.h"


void Team2::Update(float ElapsedTime)
{
	ObjectMgr::getinstance().pushteamObjects(pObject, tag);

	TeamTimer += ElapsedTime;
	selectTimer += ElapsedTime;
	if (selectTimer > 0.3f)
	{
		selectScale == 1 ? selectScale = -1 : selectScale = 1;
		selectTimer = 0.0f;
	}
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pObject[i] != NULL)
		{
			pObject[i]->Update(ElapsedTime);

		}
	}
}
void Team2::RenderSelect(Renderer* p)
{
	p->DrawTexturedRectSeq(-225, -375, 0, 50, 1, 1, 1, 1, TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER),
		0, 0, 6, 2, LEVEL_UI);

	p->DrawTexturedRectSeq(-170, -375, 0, 50, 1, 1, 1, 1, TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER_ARROW),
		0, 0, 6, 2, LEVEL_UI);
	p->DrawTexturedRectSeq(-115, -375, 0, 50, 1, 1, 1, 1, TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER_DEFENSE),
		0, 0, 6, 2, LEVEL_UI);
	int t = (TeamTimer / CREATECHARACHTER);
	int t1 = (TeamTimer / CREATEARROWCHARACHTER);
	int t2 = (TeamTimer / CREATEDEFENSECHARACHTER);

	p->DrawSolidRectGauge(-225, -375, 30, 50 + (t * selectScale  * 1.5f), 50 + (t * selectScale *1.5f), selectR_Color[0], 0, 1, 1, ((TeamTimer / CREATECHARACHTER)), LEVEL_UI + 0.005f);
	p->DrawSolidRectGauge(-170, -375, 30, 50 + (t1 * selectScale * 1.5f), 50 + (t1 * selectScale *1.5f), selectR_Color[1], 0, 1, 1, ((TeamTimer / CREATEARROWCHARACHTER)), LEVEL_UI + 0.005f);
	p->DrawSolidRectGauge(-115, -375, 30, 50 + (t2 * selectScale * 1.5f), 50 + (t2 * selectScale * 1.5f), selectR_Color[2], 0, 1, 1, ((TeamTimer / CREATEDEFENSECHARACHTER)), LEVEL_UI + 0.005f);
}

void Team2::Render(Renderer* p)
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pObject[i] != NULL)
		{
			pObject[i]->Render(p);

		}
	}
	p->DrawSolidRect(0, -107.5f, 0, 220, 0, 1, 1, 0.2f, 0.85f);
	p->DrawSolidRect(-150, -107.5f, 0, 220, 0, 1, 1, 0.2f, 0.87f);
	p->DrawSolidRect(150, -107.5f, 0, 220, 0, 1, 1, 0.2f, 0.88f);
	RenderSelect(p);
	//p->DrawSolidRectGauge(-225, -375, 30, 50, 50, selectR_Color[0], 0, 1, 1, ((TeamTimer / CREATECHARACHTER)), LEVEL_UI + 0.005f);


}
void Team2::Key(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
		CreateKeyType = 0;
	else if (key == GLUT_KEY_F2)
		CreateKeyType = 1;
	else if (key == GLUT_KEY_F3)
		CreateKeyType = 2;
	for (int i = 0; i < 3; ++i)
		selectR_Color[i] = 0.0f;
	selectR_Color[CreateKeyType] = 1.0f;

}
void Team2::Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		int tempx = x - 250;
		int tempy = 400 - y;
		if (state == GLUT_DOWN)
		{
			if (tempy < 0 && tempy > -210)
			{
				if (TeamTimer >= createTimer[CreateKeyType])
				{
					CreateCharacter(tempx, tempy);
					TeamTimer = 0.0f;
					return;
				}
			}
		}
	}
}
void Team2::CreateCharacter(int x, int y)
{
	
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
