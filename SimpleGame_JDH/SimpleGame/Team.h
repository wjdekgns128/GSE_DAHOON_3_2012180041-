#pragma once
#include "BaseObject.h"
#include "Building.h"
#include "Character.h"
#include "CharacterArrow.h"
#include "CharacterDefense.h"
class Team
{
protected:
	float createTimer[3];
	int	CreateKeyType;
	float  TeamTimer;
	TEAMTAG tag;
	BaseObject*		pObject[MAX_OBJECT__COUNT];
public:
	Team()
	{
		createTimer[0] = CREATECHARACHTER;
		createTimer[1] = CREATEARROWCHARACHTER;
		createTimer[2] = CREATEDEFENSECHARACHTER;
		TeamTimer = 0.0f;
		CreateKeyType = 0;
	}
	virtual ~Team()
	{
	}
public:
	virtual void Update(float ElapsedTime) = 0;
	virtual void Render(Renderer* p) = 0;
	virtual void Mouse(int button, int state, int x, int y) = 0;
	virtual void Key(int key, int x, int y) = 0;
protected:
	
public:
#pragma region get,set
	BaseObject** GetObjects()
	{
		return  pObject;
	}
#pragma endregion

};
