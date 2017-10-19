#include "stdafx.h"
#include "Object.h"

void Object::Update()
{
	
	MyVector m(tempx,tempy, 0); // 방향백터
	vector = vector + (m * Speed * 1); // 시간

	if (vector.x <= -249 || vector.x >=249)
	{
		tempx *= -1;
	}
	if (vector.y <= -249 || vector.y >= 249)
	{
		tempy *= -1;
	}

}
void Object::Render(Renderer* p)
{
	p->DrawSolidRect(vector.x, vector.y, vector.z,size,r,g,b,a);
}