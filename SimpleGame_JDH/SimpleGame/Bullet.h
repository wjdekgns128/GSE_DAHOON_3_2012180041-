#pragma once
#include <stdio.h>
#include "BaseObject.h"
#include "ObjectMgr.h"
// 최우선으로 디펜더 -> 빌딩 -> 캐릭터 - > 총쏘는 캐릭터 공격
class Bullet : public BaseObject
{
private:
	MyVector moveVector;
	float	 ParticleTime;
public:
	Bullet(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime,float speed) : BaseObject(type, tag, vec, color, size, life, lifetime,speed)
	{
		ParticleTime = 0.0f;
	//이 부분 수정
		dietimer = 0.0f;
		moveVector = GetMinDisByMaskObjects(4,
			PRIORITY(OBJECTTYPE::CHARACHTER_DEFENSE, 0.2f),
			PRIORITY(OBJECTTYPE::CHARACHTER, 2.4f), 
			PRIORITY(OBJECTTYPE::CHARACHTER_ARROW, 3.6f), 
			PRIORITY(OBJECTTYPE::BUILDING, 1.7f));
		if (moveVector.x == -9999)
			state = 2;
		moveVector = (moveVector -vec );
		moveVector.Nomalizing();

	}

	~Bullet()
	{

	}

public:

public:
	void Update(float timer);
	void Render(Renderer* p);
	void CollProcessing(BaseObject* p);

private:

};