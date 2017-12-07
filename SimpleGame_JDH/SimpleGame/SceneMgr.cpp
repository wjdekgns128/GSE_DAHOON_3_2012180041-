#include "stdafx.h"
#include "SceneMgr.h"
#include "TexturData.h"
SceneMgr::SceneMgr()
{
	SceneRenderer = NULL;
	pSound = NULL;
	for (int i = 0; i < 2; ++i)
		pTeam[i] = NULL;
}
SceneMgr::~SceneMgr()
{
	SAFE_DELETE(pSound);
	SAFE_DELETE(SceneRenderer);
	for (int i = 0; i < 2; ++i)
		SAFE_DELETE(pTeam[i]);

}
void SceneMgr::TextureLoad()
{
	//TEXTUREID
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM1_Building.png"), TEX_TEAM_1_BUILDING);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM2_Building.png"), TEX_TEAM_2_BUILDING);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM1_Character.png"), TEX_TEAM_1_CHARACTER);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM2_Character.png"), TEX_TEAM_2_CHARACTER);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/Background.png"), TEX_BACKGROUND);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/Bullet.png"), TEX_BULLET);
}
void SceneMgr::Init()
{
	if (SceneRenderer == NULL)
	{
		SceneRenderer = new Renderer(500, 800);
		if (!SceneRenderer->IsInitialized())
		{
			std::cout << "Renderer could not be initialized.. \n";
		}
	}

	TextureLoad();

	pTeam[0] = new Team1();
	pTeam[1] = new Team2();


	if (pSound == NULL)
	{
		pSound = new Sound();
		int soundBG = pSound->CreateSound("Dependencies/SoundSamples/MF-W-90.XM");
		pSound->PlaySound(soundBG, true, 0.2f);
	}


	//GLUT_BITMAP_9_BY_15
}
void SceneMgr::Destory()
{
	SAFE_DELETE(pSound);
	SAFE_DELETE(SceneRenderer);
	for (int i = 0; i < 2; ++i)
		SAFE_DELETE(pTeam[i]);
}
void SceneMgr::Update(DWORD ElapsedTime)
{
	for (int i = 0; i < 2; ++i)
	{
		if (pTeam[i] != NULL)
		{
			pTeam[i]->Update((float)ElapsedTime * 0.001f);
		}
	}
	SceneRenderer->DrawTextW(0, 0, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1, "Test Draw");
	CollManager();
}
void SceneMgr::CollManager()
{
	int count = 0;
	int count1 = 0;
	BaseObject* p[500] = { NULL, };
	BaseObject* p1[500] = { NULL, };
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pTeam[0]->GetObjects()[i] != NULL)
		{
			p[count++] = pTeam[0]->GetObjects()[i];
			for (int j = 0; j < MAX_OBJECT__COUNT; ++j)
			{
				if (pTeam[0]->GetObjects()[i]->getType() == OBJECTTYPE::CHARACHTER)
				{
					Character* d = (Character*)pTeam[0]->GetObjects()[i];
					if(d->getArrows()[j] != NULL)
					p[count++] = d->getArrows()[j];
				}
				else if (pTeam[0]->GetObjects()[i]->getType() == OBJECTTYPE::BUILDING)
				{
					Building* d = (Building*)pTeam[0]->GetObjects()[i];
					if (d->getBullets()[j] != NULL)
					p[count++] = d->getBullets()[j];
				}
			}
		}
	}
	 count = 0;
	 count1 = 0;
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pTeam[1]->GetObjects()[i] != NULL)
		{
			p1[count++] = pTeam[1]->GetObjects()[i];
			for (int j = 0; j < MAX_OBJECT__COUNT; ++j)
			{
				if (pTeam[1]->GetObjects()[i]->getType() == OBJECTTYPE::CHARACHTER)
				{
					Character* d = (Character*)pTeam[1]->GetObjects()[i];
					if (d->getArrows()[j] != NULL)
						p1[count++] = d->getArrows()[j];
				}
				else if (pTeam[1]->GetObjects()[i]->getType() == OBJECTTYPE::BUILDING)
				{
					Building* d = (Building*)pTeam[1]->GetObjects()[i];
					if (d->getBullets()[j] != NULL)
						p1[count++] = d->getBullets()[j];
				}
			}
		}
	}
	for (int i = 0; i < 500; ++i)
	{
		for (int j = 0; j < 500; ++j)
		{
			if (p[i] != NULL)
			{
				if (p1[j] != NULL)
					if (p[i]->CollByObject(p1[j]))
					{
						p[i]->CollProcessing(p1[j]);
						p1[j]->CollProcessing(p[i]);
					}

			}
		}
	}
}
void SceneMgr::Render()
{
	SceneRenderer->DrawTexturedRect(0,0,0,800,1,1,1,1,TexturData::getinstance().getTextur(TEX_BACKGROUND), LEVEL_BACK);
	for (int i = 0; i < 2; ++i)
	{
		if (pTeam[i] != NULL)
		{
			pTeam[i]->Render(SceneRenderer);
		}
	}
}
void SceneMgr::Mouse(int button, int state, int x, int y)
{
	for (int i = 0; i < 2; ++i)
	{
		if (pTeam[i] != NULL)
		{
			pTeam[i]->Mouse(button, state, x, y);
		}
	}
}
