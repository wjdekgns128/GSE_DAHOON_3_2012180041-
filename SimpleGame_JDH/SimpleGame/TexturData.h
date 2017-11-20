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
	void Input(unsigned int n, TEXTURE num)
	{
		Number[(int)num] = n;
	}
	unsigned int getTextur(TEXTURE num)
	{
		return Number[(int)num];
	}
};