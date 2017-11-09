#include "stdafx.h"
#include "Arrow.h"

void Arrow::Update(DWORD timer)
{
	// �������
	float sce = (float)timer / 1000.0;
	float s = Speed* sce;
	vector.x = vector.x + (Move.x * (Speed * sce)); // �ð�
	vector.y = vector.y + (Move.y * (Speed * sce)); // �ð�
	if (vector.x <= -250 + size / 2 || vector.x >= 250 - size / 2)
	{
		state = 2;
	}
	if (vector.y <= -250 + size / 2 || vector.y >= 250 - size / 2)
	{
		state = 2;
	}
}
void Arrow::Render(Renderer* p)
{
	p->DrawSolidRect(vector.x, vector.y, vector.z, size, r, g, b, a);
}
void Arrow::CollByObject(float down)
{
	state = 2;
}




