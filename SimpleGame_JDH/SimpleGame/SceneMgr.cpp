
#include "stdafx.h"
#include "SceneMgr.h"
#include "TexturData.h"
#include "ObjectMgr.h"
SceneMgr::SceneMgr()
{
	climateTime = 0.0f;
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
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM1_Character_Bullet.png"), TEX_TEAM_1_CHARACTER_ARROW);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM2_Character_Bullet.png"), TEX_TEAM_2_CHARACTER_ARROW);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM1_Character_Defense.png"), TEX_TEAM_1_CHARACTER_DEFENSE);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/TEAM2_Character_Defense.png"), TEX_TEAM_2_CHARACTER_DEFENSE);
	TexturData::getinstance().Input(SceneRenderer->CreatePngTexture("res/rain.png"), TEX_RAIN);
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
	//SceneRenderer->DrawTextW(0, 0, GLUT_BITMAP_TIMES_ROMAN_24, 1, 1, 1, "Test Draw");
	climateTime += (float)ElapsedTime * 0.001f;
	CollManager();
}
void SceneMgr::CollManager()
{
	int count = 0;
	int count1= 0;

	BaseObject** Team1 = NULL;
	BaseObject** Team2 = NULL;
	Team1 = ObjectMgr::getinstance().pullteamObjects(TEAMTAG::TEAM_1);
	Team2 = ObjectMgr::getinstance().pullteamObjects(TEAMTAG::TEAM_2);
	Team1 = getAllObject(Team1, TEAMTAG::TEAM_1,&count);
	Team2= getAllObject(Team2, TEAMTAG::TEAM_2,&count1);
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count1; ++j)
		{
			if (Team1[i]->CollByObject(Team2[j]))
			{
				printf("Ãæµ¹\n");
			}
		}
	}
}
BaseObject** SceneMgr::getAllObject(BaseObject** p1, int tag,int* count)
{
	BaseObject** ReturnArray = p1;
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (p1[i] != NULL)
		{
			Building* P1 = dynamic_cast<Building*>(p1[i]);
			CharacterArrow* P2 = dynamic_cast<CharacterArrow*>(p1[i]);
			CharacterDefense* P3 = dynamic_cast<CharacterDefense*>(p1[i]);
			if (P1 != NULL)
			{
				for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
				{
					if (P1->getBullets()[i] != NULL)
					{
						ReturnArray[*count++] = (P1)->getBullets()[i];
					}
				}
			}
			else if (P2 != NULL)
			{
				for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
				{
					if (P2->getArrow()[i] != NULL)
					{
						ReturnArray[*count++] = (P2)->getArrow()[i];
					}
				}
			}
			else if (P3 != NULL)
			{
				for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
				{
					if (P3->getArrowDefense()[i] != NULL)
					{
						ReturnArray[*count++] = (P3)->getArrowDefense()[i];
					}
				}
			}
		} 
	}
	return ReturnArray;
}
void SceneMgr::Key(int key, int x, int y)
{
	for (int i = 0; i < 2; ++i)
	{
		if (pTeam[i] != NULL)
		{
			pTeam[i]->Key(key, x, y);
		}
	}
}
void SceneMgr::Render()
{
	SceneRenderer->DrawTexturedRect(0, 0, 0, 800, 1, 1, 1, 1, TexturData::getinstance().getTextur(TEX_BACKGROUND), LEVEL_BACK);
	for (int i = 0; i < 2; ++i)
	{
		if (pTeam[i] != NULL)
		{
			pTeam[i]->Render(SceneRenderer);
		}
	}
	SceneRenderer->DrawParticleClimate(0, 0, 0, 1.0f, 1, 1, 1, 1, -0.2f, -0.2f,
		TexturData::getinstance().getTextur(TEX_RAIN), climateTime, 0.01);
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
