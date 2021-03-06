#pragma once
#include "Team.h"
#include "ObjectMgr.h"

class Team2 : public Team
{
protected:
	
public:
	Team2()
	{
	


		tag = TEAMTAG::TEAM_2;
		TeamTimer = 0.0f;
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			pObject[i] = NULL;
		MyVector Bullpos[] = {MyVector(-180,-300,0) ,MyVector(0,-320,0) ,MyVector(180,-300,0) };

		for (int i = 0; i < 3; ++i)
		{
			pObject[i] = new Building(OBJECTTYPE::BUILDING, tag, Bullpos[i], MyColor(1, 1, 1, 1),
				100, 700.0f, 999999);
		}
		createTimer[0] = CREATECHARACHTER;
		createTimer[1] = CREATEARROWCHARACHTER;
		createTimer[2] = CREATEDEFENSECHARACHTER;
	}
	~Team2()
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			SAFE_DELETE(pObject[i]);
	}
public:
	void Update(float ElapsedTime);
	void Render(Renderer* p);
	void Mouse(int button, int state, int x, int y);
	void Key(int key, int x, int y);

private:
	void RenderSelect(Renderer* p);
	void CreateCharacter(int x, int y);

};
