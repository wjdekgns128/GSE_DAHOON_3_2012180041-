#pragma once
#include "Singleton.h"
class TexturData : public Singleton<TexturData>
{
	unsigned int Number[1000];
public:
	TexturData()
	{

	}
	~TexturData()
	{

	}
public:
	void Input(unsigned int n, TEXTUREID num)
	{
		Number[(int)num] = n;
	}
	unsigned int getTextur(TEXTUREID num)
	{
		return Number[(int)num];
	}
};