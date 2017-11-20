#pragma once

class MyColor
{
public:
	float r, g, b, a;

	MyColor()
	{
		r = g = b = a = 0.0f;
	}
	MyColor(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	MyColor(const MyColor& c)
	{
		r = c.r;
		g = c.g;
		b = c.b;
		a = c.a;
	}
};