#include "stdafx.h"
#include "Bullet.h"

void Bullet::Update(DWORD timer)
{
	 // 방향백터
	float sce = (float)timer / 1000.0;
	float s = Speed* sce;
	vector.x = vector.x + (Move.x * (Speed * sce)); // 시간
	vector.y = vector.y + (Move.y * (Speed * sce)); // 시간
	if (vector.x <= -250 + size / 2 || vector.x >= 250 - size / 2)
	{
		state = 2;
	}
	if (vector.y <= -250 + size / 2 || vector.y >= 250 - size / 2)
	{
		state = 2;
	}
}
void Bullet::Render(Renderer* p)
{
	p->DrawSolidRect(vector.x, vector.y, vector.z, size, r, g, b, a);
}
void Bullet::CollByObject(float down)
{
	state = 2;
}




