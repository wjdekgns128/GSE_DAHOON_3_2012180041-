#pragma once
#include <stdio.h>
#include "Arrow.h"
#include "BaseObject.h"
#include "TexturData.h"
#include "ObjectMgr.h"

//// ÃÑ½ô ( ÃÑ½î´Â³ð ÃÖ¿ì¼±) - > µðÆæ´õ -> ¾øÀ¸¸é ºôµù¿¡ °ø°Ý
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
	CharacterArrow(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime, float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		CreateArrowTimer = 0.0f;
		for (int i = 0; i < 300; ++i)
			pArrow[i] = NULL;
		NowX = 0;
		NowY = 0;
		AnimatorTime = 0.0f;
		moveVector = GetMinDisByMaskObjects(1,
			PRIORITY(OBJECTTYPE::BUILDING, 1.0f));

		moveVector = (moveVector - vec);
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