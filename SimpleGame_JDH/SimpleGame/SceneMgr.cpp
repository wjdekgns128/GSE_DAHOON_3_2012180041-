#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
		b[i] = NULL;
	g_Renderer = NULL;
}
SceneMgr::~SceneMgr()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			b[i] = NULL;
			delete b[i];

		}
	}
	if (g_Renderer != NULL)
	{
		delete g_Renderer;
		g_Renderer = NULL;
	}

}
void SceneMgr::Init()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		float TempSpeed = 3 - rand() % 6;
		TempSpeed == 0 ? TempSpeed = 1 : TempSpeed = TempSpeed;
		b[i] = new Object(MyVector(rand() % 500 - 250, rand() % 500 - 250, 0), 10, 1, 1, 1, 1, TempSpeed);
	}
	if (g_Renderer == NULL)
	{
		g_Renderer = new Renderer(500, 500);
		if (!g_Renderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}
	}
}
void SceneMgr::Destory()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			delete b[i];
			b[i] = NULL;
		}
	}
	if (g_Renderer != NULL)
	{
		delete g_Renderer;
		g_Renderer = NULL;
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
void SceneMgr::Render()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			b[i]->Render(g_Renderer);
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
			if (BoxToBoxColl(b[i]->getVector().x, b[i]->getVector().y, b[i]->getSize(), b[i]->getSize(), b[j]->getVector().x, b[j]->getVector().y, b[j]->getSize(), b[j]->getSize()))
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
bool SceneMgr::BoxToBoxColl(float x, float y, float w, float h, float x1, float y1, float w1, float h1)
{
	return x + w >=x1 && x <= x1+w1
		&&  y + h>=y1 &&y <= y1 + h1;
}