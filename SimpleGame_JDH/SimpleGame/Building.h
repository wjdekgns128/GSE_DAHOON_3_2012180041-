#pragma once
#include <stdio.h>
#include "BaseObject.h"
#include "Bullet.h"
#include "TexturData.h"

class Building : public BaseObject
{
private:
	unsigned int TexID;
	float       createBulletTimer;
	Bullet*		pBullet[MAX_OBJECT__COUNT];
	MyColor   HpBarColor;
public:
	Building(OBJECTTYPE type,TEAMTAG tag, MyVector vec, MyColor color, float size, float life, float lifetime) : BaseObject(type,tag,vec,color,size,life,lifetime,0)
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			pBullet[i] = NULL;
		createBulletTimer = 0.0f;
		tag == TEAMTAG::TEAM_1 ?
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_1_BUILDING) :
			TexID = TexturData::getinstance().getTextur(TEX_TEAM_2_BUILDING);
		tag == TEAMTAG::TEAM_1 ?
			HpBarColor.SetColor(1, 0, 0, 1) :
			HpBarColor.SetColor(0, 0, 1, 1);
	}
	
	~Building()
	{
		for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
			SAFE_DELETE(pBullet[i]);
	}

public:
	Bullet** getBullets()
	{
		return pBullet;
	}
public:
	void Update(float timer);
	void Render(Renderer* p);
	void CollProcessing(BaseObject* p);

private:
	void CreateBullet();

};