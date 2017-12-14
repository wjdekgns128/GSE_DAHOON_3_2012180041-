#pragma once
#include <stdio.h>
#include "Arrow.h"
#include "BaseObject.h"
#include "TexturData.h"
#include "ObjectMgr.h"

//// 돌진형 빌딩에만 공격.
class Character : public BaseObject
{
private:
	MyColor   HpBarColor;
	float		waitMoveTimer;
	int       waitRandomTimer;
	MyVector moveVector;
	unsigned int TexID;
	

	int				NowX;
	int				NowY;
	float			AnimatorTime;

public:
	Character(OBJECTTYPE type, TEAMTAG tag, MyVector vec,MyColor color, float size, float life, float lifetime, float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		NowX = 0;
		NowY = 0;
		AnimatorTime = 0.0f;
		waitRandomTimer = rand() % 3 + 4;
		waitMoveTimer = 0.0f;
		printf("기달리는 시간 : %d\n", waitRandomTimer);

		moveVector = GetMinDisByMaskObjects(1,
			PRIORITY(OBJECTTYPE::BUILDING, 1.0f));
		if (moveVector.x == -9999)
			state = 2;
		moveVector = (moveVector - vec);
		moveVector.Nomalizing();

		tag == TEAMTAG::TEAM_1 ?
			HpBarColor.SetColor(1, 0, 0, 1) :
			HpBarColor.SetColor(0, 0, 1, 1);

		tag == TEAMTAG::TEAM_1 ?
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_1_CHARACTER) :
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER);
	}

	~Character()
	{
	
	}

public:
	
public:
	void Update(float timer);
	void Render(Renderer* p);
	virtual void CollProcessing(BaseObject* p);
private:
	void PlayAnimator(float timer);
};