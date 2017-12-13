#pragma once
#include "stdafx.h"
#include "Singleton.h"
#include "BaseObject.h"
#include<cstdarg>
class ObjectMgr : public Singleton<ObjectMgr>
{
private:
	BaseObject** team1_objects[2][MAX_OBJECT__COUNT];

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
			team1_objects[tag][i] = &p[i];
		}
	}
	BaseObject**  pullteamObjects(int tag)
	{
		return *team1_objects[tag];
	}

};