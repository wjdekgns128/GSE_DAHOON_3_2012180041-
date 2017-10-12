#include "stdafx.h"
#include "Object.h"

void Object::Update()
{
	

	MyVector m(-0.7,-0.1, 0); // 방향백터
	vector = vector + (m * Speed * 1); // 시간
}
void Object::Render(Renderer* p)
{
	p->DrawSolidRect(vector.x, vector.y, vector.z,size,r,g,b,a);
}