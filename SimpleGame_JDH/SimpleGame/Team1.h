#pragma once
#include "Team.h"
#include "ObjectMgr.h"
#include <ctime>
class Team1 : public Team
{
protected:

public:
	Team1()
	{
		srand((unsigned int)time(NULL));
		tag = TEAMTAG::TEAM_1;
		TeamTimer = 0.0f;
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			pObject[i] = NULL;
		MyVector Bullpos[] = { MyVector(-180, 300, 0), MyVector(0, 320, 0), MyVector(180, 300, 0) };
		for (int i = 0; i < 3; ++i)
		{

			pObject[i] = new Building(OBJECTTYPE::BUILDING, tag, Bullpos[i], MyColor(1, 1, 1, 1),
				100, 700.0f, 999999);

		}
		createTimer[0] = CREATECHARACHTER - 0.5f;
		createTimer[1] = CREATEARROWCHARACHTER - 0.5f;
		createTimer[2] = CREATEDEFENSECHARACHTER -0.5f;
	
	}
	~Team1()
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
	void CreateCharacter();
	void RenderSelect(Renderer* p);
	
	void FindCreateObjectType();
};
