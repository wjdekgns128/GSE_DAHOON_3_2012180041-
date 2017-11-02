#include "stdafx.h"
#include "Character.h"

void Character::Update(DWORD timer)
{
	
	MyVector m(tempx,tempy, 0); // 방향백터
	float sce = (float)timer / 1000.0;
	vector = vector + (m * Speed * sce); // 시간

	if (vector.x <= -250 + size/2|| vector.x >=250 - size/2)
	{
		tempx *= -1;
	}
	if (vector.y <= -250 + size/2 || vector.y >= 250 - size/2)
	{
		tempy *= -1;
	}
	if (state == 1)
	{
		saveTime += sce;
		if (saveTime >= lifeTime)
		{
			state = 2;
		}
	}
}
void Character::Render(Renderer* p)
{
	p->DrawSolidRect(vector.x, vector.y, vector.z,size,r,g,b,a);
}
void Character::CollByObject(float down)
{
	life -= down;
	printf("캐릭터 hp %f\n", life);
	if (life <= 0.0f)
	{
		state = 2;
	}

}

