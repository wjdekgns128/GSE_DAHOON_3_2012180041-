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
			if (BoxToBoxColl(b[i]->getVector().x, b[i]->getVector().y, b[i]->getSize(), b[i]->getSize(), b[j]->getVector().x, b[j]->getVector().y, b[j]->getSize(), b[j]->getSize()))
			{
				b[i]->setRGBA(1, 0, 0, 1);
				b[j]->setRGBA(1, 0, 0, 1);
				b[i]->CollByObject(0.1f);
				b[j]->CollByObject(0.1f);

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
					float TempSpeed = 3 - rand() % 6;
					TempSpeed == 0 ? TempSpeed = 100 : TempSpeed = TempSpeed * 500;
					b[i] = new Object(MyVector(x - 250, 250 - y, 0), 20, 1, 1, 1, 1, TempSpeed);
					break;

				}
			}

		}
	}

}