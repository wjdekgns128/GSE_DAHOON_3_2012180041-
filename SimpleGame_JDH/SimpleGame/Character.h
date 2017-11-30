#pragma once
#include <stdio.h>
#include "Arrow.h"
#include "BaseObject.h"
#include "TexturData.h"

class Character : public BaseObject
{
private:
	MyColor   HpBarColor;
	float		waitMoveTimer;
	int       waitRandomTimer;
	float       createArrowTimer;
	MyVector moveVector;
	Arrow*		pArrow[MAX_OBJECT__COUNT];
	unsigned int TexID;
	

	int				NowX;
	int				NowY;
	float			AnimatorTime;
public:
	Character(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyVector Target, MyColor color, float size, float life, float lifetime,float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		NowX = 0;
		NowY = 0;
		AnimatorTime = 0.0f;
		waitRandomTimer = rand() % 10 + 4;
		waitMoveTimer = 0.0f;
		printf("기달리는 시간 : %d\n", waitRandomTimer);

		moveVector = Target- vec;
		moveVector.Nomalizing();
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			pArrow[i] = NULL;
		createArrowTimer = 0.0f;
		tag == TEAMTAG::TEAM_1 ?
			HpBarColor.SetColor(1, 0, 0, 1) :
			HpBarColor.SetColor(0, 0, 1, 1);

		tag == TEAMTAG::TEAM_1 ?
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_1_CHARACTER) :
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER);
	}

	~Character()
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			SAFE_DELETE(pArrow[i]);
	}

public:
	Arrow** getArrows()
	{
		return pArrow;
	}
public:
	void Update(float timer);
	void Render(Renderer* p);
	virtual void CollProcessing(BaseObject* p);
private:
	void CreateArrow();
	void PlayAnimator(float timer);
};