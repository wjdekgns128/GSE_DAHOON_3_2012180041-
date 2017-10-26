#include "stdafx.h"
#include "Object.h"

void Object::Update(DWORD timer)
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
void Object::Render(Renderer* p)
{
	p->DrawSolidRect(vector.x, vector.y, vector.z,size,r,g,b,a);
}
void Object::CollByObject(float down)
{
	life -= down;
	if (life <= 0.0f)
	{
		state = 2;
		printf("\n죽음");
	}

}

