#include "stdafx.h"
#include "Object.h"

void Object::Update()
{
	

	MyVector m(-0.7,-0.1, 0); // �������
	vector = vector + (m * Speed * 1); // �ð�
}
void Object::Render(Renderer* p)
{
	p->DrawSolidRect(vector.x, vector.y, vector.z,size,r,g,b,a);
}