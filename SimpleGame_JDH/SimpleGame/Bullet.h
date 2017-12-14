#pragma once
#include <stdio.h>
#include "BaseObject.h"
#include "ObjectMgr.h"
// �ֿ켱���� ����� -> ���� -> ĳ���� - > �ѽ�� ĳ���� ����
class Bullet : public BaseObject
{
private:
	MyVector moveVector;
	float	 ParticleTime;
public:
	Bullet(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime,float speed) : BaseObject(type, tag, vec, color, size, life, lifetime,speed)
	{
	//�� �κ� ����
		dietimer = 0.0f;
		moveVector = GetMinDisByMaskObjects(4,
			PRIORITY(OBJECTTYPE::CHARACHTER_DEFENSE, 1.0f),
			PRIORITY(OBJECTTYPE::CHARACHTER, 2.1f), 
			PRIORITY(OBJECTTYPE::CHARACHTER_ARROW, 3.0f), 
			PRIORITY(OBJECTTYPE::BUILDING, 1.7f));
		if (moveVector.x == -9999)
			state = 2;
		moveVector = (moveVector -vec );
		moveVector.Nomalizing();
		ParticleTime = 0.0f;

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