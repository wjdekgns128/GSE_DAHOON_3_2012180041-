#pragma once
#include <stdio.h>
#include "Arrow.h"
#include "BaseObject.h"
#include "TexturData.h"
//// µ¹ÁøÇü
class CharacterArrow : public BaseObject
{
private:
	Arrow*		pArrow[300];
	MyColor   HpBarColor;
	MyVector moveVector;
	unsigned int TexID;

	float CreateArrowTimer;
	int				NowX;
	int				NowY;
	float			AnimatorTime;

public:
	CharacterArrow(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyVector Target, MyColor color, float size, float life, float lifetime, float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		CreateArrowTimer = 0.0f;
		for (int i = 0; i < 300; ++i)
			pArrow[i] = NULL;
		NowX = 0;
		NowY = 0;
		AnimatorTime = 0.0f;
		moveVector = Target - vec;
		moveVector.Nomalizing();

		tag == TEAMTAG::TEAM_1 ?
			HpBarColor.SetColor(1, 0, 0, 1) :
			HpBarColor.SetColor(0, 0, 1, 1);

		tag == TEAMTAG::TEAM_1 ?
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_1_CHARACTER_ARROW) :
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER_ARROW);
	}

	~CharacterArrow()
	{
		for (int i = 0; i < 300; ++i)
		SAFE_DELETE(pArrow[i]);
	}

public:

public:
	void Update(float timer);
	void Render(Renderer* p);
	virtual void CollProcessing(BaseObject* p);
private:
	void CreateArrow();
	void PlayAnimator(float timer);
};