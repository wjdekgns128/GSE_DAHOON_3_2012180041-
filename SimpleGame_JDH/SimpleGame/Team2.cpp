#include "stdafx.h"
#include "Team2.h"
#include "Dependencies\freeglut.h"


void Team2::Update(float ElapsedTime)
{
	TeamTimer += ElapsedTime;
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pObject[i] != NULL)
		{
			pObject[i]->Update(ElapsedTime);

		}
	}
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
}
void Team2::Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		int tempx = x - 250;
		int tempy = 400 - y;
		if (state == GLUT_DOWN)
		{
			if (tempy < -10 && tempy > -390)
			{
				if (TeamTimer >= 1.5f)
				{
					CreateCharacter(tempx, tempy);
					TeamTimer = 0.0f;
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
			pObject[i] = new Character(OBJECTTYPE::CHARACHTER, tag, MyVector(x, y, 0), FindTarget(), MyColor(1, 1, 1, 1), 30, 100, 9999999, 300);
			break;
		}

	}
}
