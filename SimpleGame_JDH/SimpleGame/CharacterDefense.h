#pragma once
#include <stdio.h>
#include "Arrow.h"
#include "BaseObject.h"
#include "TexturData.h"
#include "ObjectMgr.h"

// 디펜더는 움직이지는 않지만 강력한 공격으로  최우선순위 돌진 캐릭터 -> 총쏘는 캐릭터 순으로 공격.(총알이 아니라 마법구 날리게 표현.)
class CharacterDefense : public BaseObject
{
private:
	Arrow*		pArrow[MAX_OBJECT__COUNT];
	MyColor   HpBarColor;
	unsigned int TexID;

	float CreateArrowTimer;
	int				NowX;
	int				NowY;
	float			AnimatorTime;

public:
	CharacterDefense(OBJECTTYPE type, TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime, float speed) : BaseObject(type, tag, vec, color, size, life, lifetime, speed)
	{
		CreateArrowTimer = 0.0f;
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			pArrow[i] = NULL;
		NowX = 0;
		NowY = 0;
		AnimatorTime = 0.0f;

		tag == TEAMTAG::TEAM_1 ?
			HpBarColor.SetColor(1, 0, 0, 1) :
			HpBarColor.SetColor(0, 0, 1, 1);

		tag == TEAMTAG::TEAM_1 ?
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_1_CHARACTER_DEFENSE) :
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_2_CHARACTER_DEFENSE);
	}

	~CharacterDefense()
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			SAFE_DELETE(pArrow[i]);
	}

public:
	Arrow** getArrowDefense() { return pArrow; }
public:
	void Update(float timer);
	void Render(Renderer* p);
	virtual void CollProcessing(BaseObject* p);
private:
	void CreateArrow();
	void PlayAnimator(float timer);
};