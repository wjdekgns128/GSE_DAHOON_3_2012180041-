#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
		b[i] = NULL;
	SceneRenderer = NULL;
}
SceneMgr::~SceneMgr()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
		SAFE_DELETE(b[i]);
	SAFE_DELETE(SceneRenderer);

}
void SceneMgr::Init()
{

	if (SceneRenderer == NULL)
	{
		SceneRenderer = new Renderer(500, 500);
		if (!SceneRenderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}
	}
	b[0] = new Building(MyVector(0, 0, 0), 50, 1, 1, 0, 1, 0, OBJECTTYPE::BUILDING, 500);
}
void SceneMgr::Destory()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
		SAFE_DELETE(b[i]);
	SAFE_DELETE(SceneRenderer);

}
void SceneMgr::Update(DWORD ElapsedTime)
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			b[i]->Update(ElapsedTime);
			if (b[i]->getState() == 2)
			{
				SAFE_DELETE(b[i]);
			}
		}

	}
	TestColl();
	TestCollByBullet();

}
void SceneMgr::TestCollByBullet()
{
	Bullet** Temp = NULL;
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			if (b[i]->getType() == OBJECTTYPE::BUILDING)
			{
				Temp = ((Building*)b[i])->getBullet(); // ¹é°³
				break;
			}
		}
	}

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < MAX_OBJECT__COUNT; j++)
		{
			if (Temp[i] != NULL && b[j] != NULL)
			{
				if (b[j]->getType() == OBJECTTYPE::CHARACHTER)
				{
					if (BoxToBoxColl(b[j]->getVector().x, b[j]->getVector().y, b[j]->getSize(), b[j]->getSize(),
						Temp[i]->getVector().x, Temp[i]->getVector().y, Temp[i]->getSize(), Temp[i]->getSize()))
					{
						b[j]->CollByObject(Temp[i]->getLife());
						Temp[i]->CollByObject(0);
						break;
					}
				}
			}
		}

	}
}
void SceneMgr::Render()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (b[i] != NULL)
		{
			b[i]->Render(SceneRenderer);
		}
	}

}
void SceneMgr::TestColl()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		for (int j = 0; j < MAX_OBJECT__COUNT; ++j)
		{
			if (b[i] == NULL || b[j] == NULL || i == j)
				continue;

			if (b[i]->getType() == OBJECTTYPE::CHARACHTER && b[j]->getType() == OBJECTTYPE::BUILDING)
			{
				if (BoxToBoxColl(b[i]->getVector().x, b[i]->getVector().y, b[i]->getSize(), b[i]->getSize(), b[j]->getVector().x, b[j]->getVector().y, b[j]->getSize(), b[j]->getSize()))
				{
					b[i]->setState(2);
					b[j]->CollByObject(b[i]->getLife());
					break;
				}
			}



		}
	}
}
bool SceneMgr::BoxToBoxColl(float x, float y, float w, float h, float x1, float y1, float w1, float h1)
{
	return x + w >= x1 && x <= x1 + w1
		&&  y + h >= y1 &&y <= y1 + h1;
}
void SceneMgr::Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			{
				if (b[i] == NULL)
				{

					b[i] = new Character(MyVector(x - 250, 250 - y, 0), 10, 1, 1, 1, 1, 300, OBJECTTYPE::CHARACHTER, 10);
					break;

				}
			}

		}
	}

}
