#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		float TempSpeed = 3 - rand() % 6;
		TempSpeed == 0 ? TempSpeed =1 : TempSpeed= TempSpeed;
		b[i] = new Object(MyVector( rand()%500 - 250,rand()%500 - 250, 0), 10, 1, 1, 1, 1, TempSpeed);

	}
}
SceneMgr::~SceneMgr()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
			delete b[i];
	}
}
void SceneMgr::Update()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			b[i]->Update();
		}
	}
	TestColl();

}
void SceneMgr::Render(Renderer* pr)
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			b[i]->Render(pr);
		}
	}

}
void SceneMgr::TestColl()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		for (int j = 0; j < MAX_OBJECT__COUNT; ++j)
		{
			if (i == j)
				continue;
		/*	float left = 250 + b[i]->getVector().x - 0.5f;
			float right = 250 + b[i]->getVector().x + 0.5f;
			float top = 250 + b[i]->getVector().y + 0.5f;
			float bom = 250 + b[i]->getVector().y - 0.5f;
			float left1 = 250 + b[j]->getVector().x - 0.5f;
			float right1 = 250 + b[j]->getVector().x + 0.5f;
			float top1 = 250 + b[j]->getVector().y + 0.5f;
			float bom1 = 250 + b[j]->getVector().y - 0.5f;
		
			if (left < right1  && top < bom1 && right > left1 && bom > top1)
			{
				b[i]->setRGBA(1, 0, 0, 1);
				b[j]->setRGBA(1, 0, 0, 1);
				return;
			}*/
			float  l = sqrt(pow(b[i]->getVector().x - b[j]->getVector().x, 2) + pow(b[i]->getVector().y - b[j]->getVector().y, 2));
			if (l <= b[i]->getSize()+1.5f)
			{
				b[i]->setRGBA(1, 0, 0, 1);
				b[j]->setRGBA(1, 0, 0, 1);
				return;
			}
			else
			{
				b[i]->setRGBA(1, 1, 1, 1);
				b[j]->setRGBA(1, 1, 1, 1);
			}
		}
	}
}