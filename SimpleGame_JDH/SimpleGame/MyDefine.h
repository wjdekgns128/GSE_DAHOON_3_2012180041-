#pragma once
#include <stdio.h>

#define SAFE_DELETE(p) {if(p != NULL) {delete p; p = NULL;}}
#define MAX_OBJECT__COUNT 100
const float      LEVEL_BACK = 0.9f;
const  float	 LEVEL_UI = 0.1F;
const  float	 LEVEL_BUILDING = 0.2F;
const  float	 LEVEL_CHARACTER = 0.3F;
const  float	 LEVEL_BULLET = 0.4F;
const  float	 LEVEL_ARROW = 0.4F;
enum OBJECTTYPE
{
	CHARACHTER =0,
	BUILDING,
	BULLET,
	ARROW,
};
enum TEAMTAG
{
	TEAM_1 = 0,
	TEAM_2,
};
enum TEXTUREID
{
	TEX_TEAM_1_BUILDING = 0,
	TEX_TEAM_2_BUILDING,
	TEX_TEAM_1_CHARACTER,
	TEX_TEAM_2_CHARACTER,
	TEX_BACKGROUND,
	TEX_BULLET,
};