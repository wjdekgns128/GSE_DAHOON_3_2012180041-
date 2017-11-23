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
	if (TeamTimer > 1.5f)
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
}
void Team1::CreateCharacter()
{
	int x = rand() % 481 - 240;
	int y = rand() % 220 + 20;
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pObject[i] == NULL)
		{
			pObject[i] = new Character(OBJECTTYPE::CHARACHTER, tag, MyVector(x, y, 0),FindTarget(), MyColor(1, 1, 1, 1), 30, 100, 9999999, 300);
			break;
		}

	}
}
void Team1::Mouse(int button, int state, int x, int y)
{

}
