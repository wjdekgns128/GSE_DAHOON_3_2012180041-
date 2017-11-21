#include "stdafx.h"
#include "Building.h"
#include "TexturData.h"
void Building::Update(float timer)
{
	if (state != 1)
		return;
	dietimer += timer;
	createBulletTimer += timer;

	if (createBulletTimer >= 10.0f)
	{
		CreateBullet();
		createBulletTimer = 0.0f;
	}
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pBullet[i] != NULL)
		{
			pBullet[i]->Update(timer);
			if (pBullet[i]->getState() == 2)
			{
				SAFE_DELETE(pBullet[i]);
			}
		}
	}
	if (dietimer >= lifetime)
	{
		state = 2;
	}
}
void Building::Render(Renderer* p)
{
	if (state != 1)
		return;
	unsigned int TexID;
	tag == TEAMTAG::TEAM_1 ?
		TexID = TexturData::getinstance().getTextur(TEX_TEAM_1_BUILDING) :
		TexID = TexturData::getinstance().getTextur(TEX_TEAM_2_BUILDING);
	p->DrawTexturedRect(vec.x, vec.y, vec.z, size, color.r, color.g, color.b, color.a, TexID);
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pBullet[i] != NULL)
			pBullet[i]->Render(p);
	}
	//p->DrawSolidRect(vector.x, vector.y, vector.z, size, r, g, b, a);
}

void Building::CreateBullet()
{
	for (int i = 0; i < MAX_OBJECT__COUNT; ++i)
	{
		if (pBullet[i] == NULL)
		{
			MyColor t1(1,0,0,1);
			MyColor t2(0, 0, 1, 1);
			MyColor temp;
			tag == TEAMTAG::TEAM_1 ? temp = t1 : temp = t2;

			pBullet[i] = new Bullet(OBJECTTYPE::BULLET, tag, vec, temp, 5, 20, 999999,600); // 크기가 너무작아서 5로 수정.
			break;
		}
	}
}



void Building::CollProcessing(BaseObject* p)
{
	switch (p->getType())
	{

	case OBJECTTYPE::CHARACHTER:
	case OBJECTTYPE::ARROW:
		life -= p->getLife();
		if (life <= 0)
			state = 2;
		printf("빌딩 남은 체력 : %f\n", life);

		break;
	}

}



