#pragma once
#include <Windows.h>
#include "MyVector.h"
#include "MyColor.h"
#include "Renderer.h"
#include "MyDefine.h"
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
