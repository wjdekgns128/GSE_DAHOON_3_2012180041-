#include "stdafx.h"
#include "Building.h"

void Building::Update(DWORD timer)
{
	float sce = (float)timer / 1000.0;
	savetimer += sce;
	if (savetimer >= 0.5f)
	{
		CreateBullet();
		savetimer = 0.0f;
	}
	for (int i = 0; i < 100; ++i)
	{
		if (pBullet[i] != NULL)
		{
			pBullet[i]->Update(timer);

			if (pBullet[i]->getState() == 2)
			{
				SAFE_DELETE(pBullet[i]);
			}
		}
	}
}
void Building::Render(Renderer* p)
{
	if (Texid == -999)
	{
		Texid = p->CreatePngTexture("res/Building.png");
	}
	for (int i = 0; i < 100; ++i)
	{
		if(pBullet[i] != NULL)
		pBullet[i]->Render(p);
	}
	p->DrawTexturedRect(vector.x, vector.y, vector.z, size, r, g, b, a, Texid);
	//p->DrawSolidRect(vector.x, vector.y, vector.z, size, r, g, b, a);
}
void Building::CollByObject(float down)
{
	life -= down;
	if (life <= 0)
		state = 2;
	printf("ºôµù ¿¡³ÊÁö %f\n", life);
}

void Building::CreateBullet()
{
	for (int i = 0; i < 100; ++i)
	{
		if (pBullet[i] == NULL)
		{
			pBullet[i] = new Bullet(vector, 4, 0, 1, 1, 1, 300, OBJECTTYPE::BULLET,10);
			break;
		}
	}
}


