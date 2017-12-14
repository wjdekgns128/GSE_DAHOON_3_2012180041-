#pragma once
#include "ObjectMgr.h"
#include <Windows.h>
#include "MyVector.h"
#include "MyColor.h"
#include "Renderer.h"
#include "MyDefine.h"
#include<cstdarg>
class  BaseObject
{
protected:
	float dietimer;

	int   state;
	OBJECTTYPE type;
	TEAMTAG tag;
	MyVector   vec;
	MyColor    color;
	float		size;
	float      life;
	float      lifetime;
	float      timer;
	float     speed;
public:
	BaseObject(OBJECTTYPE type,TEAMTAG tag,MyVector vec,MyColor color,float size,float life,float lifetime,float speed) : size(size),type(type),vec(vec),color(color),life(life) , tag(tag),speed(speed), lifetime(lifetime)
	{
		state = 1;
		timer = 0.0;
		dietimer = 0.0;
	}
	virtual ~BaseObject()
	{

	}
public:
	virtual void Update(float ElapsedTime) = 0;
	virtual void Render(Renderer* p) = 0;
	virtual void CollProcessing(BaseObject* p) = 0;
#pragma region get,set
	MyVector getMyVector()const
	{
		return vec;
	}
	float getLife() const
	{
		return life;
	}
	int getState()const
	{
		return state;
	}
	OBJECTTYPE getType() const
	{
		return type;
	}
#pragma endregion
public:
	MyVector  GetMinDisByMaskObjects(int args,...) // 인자값으로 넘어오는 타입제외하고 리턴
	{
		float v[100] = { 0, };
		OBJECTTYPE TempPri[100];

		float Temp = 9999999;
		MyVector returnVec;
		returnVec.Setting(-9999, -9999, -9999);
		va_list ap;
		va_start(ap, args);
		int count = 0;
		BaseObject** p = NULL;
		if (tag == TEAMTAG::TEAM_1)
			p = ObjectMgr::getinstance().pullteamObjects(TEAMTAG::TEAM_2);
		else
			p = ObjectMgr::getinstance().pullteamObjects(TEAMTAG::TEAM_1);
		for (int i = 0; i < args; ++i)
		{
			PRIORITY Temppriority = va_arg(ap, PRIORITY);
			TempPri[i] = Temppriority.type;
			v[TempPri[i]] = Temppriority.PriorityDistance;
		}
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
		{
			if (p[i] != NULL)
			{
				bool check = false;
				for (int j = 0; j < args; ++j)
				{
					if (TempPri[j] == p[i]->getType())
					{
						check = true;
						break;
					}
				}

				if (check)
				{
					MyVector d;
					MyVector d1;

					d.Setting(vec.x + 250, vec.y + 400, 0);
					d1.Setting(p[i]->getMyVector().x + 250, p[i]->getMyVector().y + 400, 0);

					float dis = v[p[i]->getType()] * (d - d1).VectorSize();
					if (dis < Temp)
					{
						Temp = dis;
						returnVec = p[i]->getMyVector();
					}
				}
			}
		}
		va_end(ap);	
		return returnVec;
	}
	
	bool CollByObject(BaseObject* p) // 충돌체크
	{
		if (p->getState() == 2)
			return false;
		float left = vec.x - size / 2.0f;
		float top = vec.y - size / 2.0f;
		float right = vec.x + size / 2.0f;
		float bottom = vec.y + size / 2.0f;

		float left1 = p->vec.x - p->size / 2.0f;
		float top1 = p->vec.y - p->size / 2.0f;
		float right1 = p->vec.x + p->size / 2.0f;
		float bottom1 = p->vec.y + p->size / 2.0f;
		if (left	<	right1	&&
			top	<	bottom1	&&
			right	>	left1	&&
			bottom	>	top1)
		{
			return true;
				
		}
		return false;

	}
};
