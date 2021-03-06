#pragma once
#include <stdio.h>
#include "Arrow.h"
#include "BaseObject.h"
#include "TexturData.h"
#include "ObjectMgr.h"

//// �ѽ� ( �ѽ�³� �ֿ켱) - > ����� -> ������ ������ ����
class CharacterArrow : public BaseObject
{
private:
	Arrow*		pArrow[MAX_OBJECT__COUNT];
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
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
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
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
		SAFE_DELETE(pArrow[i]);
	}

public:
	Arrow** getArrow() { return pArrow; }
public:
	void Update(float timer);
	void Render(Renderer* p);
	virtual void CollProcessing(BaseObject* p);
private:
	void CreateArrow();
	void PlayAnimator(float timer);
};