#pragma once
#include "stdafx.h"
#include "BaseObject.h"

#include "Singleton.h"

class BaseObject;
class ObjectMgr : public Singleton<ObjectMgr>
{
private:
	BaseObject** team_objects[2][MAX_OBJECT__COUNT];

public:
	ObjectMgr()
	{

	}
	~ObjectMgr()
	{

	}
public:
	void pushteamObjects(BaseObject** p,int tag)
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
		{
			team_objects[tag][i] = &p[i];
		}
	}
	BaseObject**  pullteamObjects(int tag)
	{
		return *team_objects[tag];
	}

};