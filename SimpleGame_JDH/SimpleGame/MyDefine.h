#pragma once
#include <stdio.h>

#define SAFE_DELETE(p) {if(p != NULL) {delete p; p = NULL;}}
#define MAX_OBJECT__COUNT 100

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
enum TEXTURE
{
	TEX_TEAM_1_BUILDING = 0,
	TEX_TEAM_2_BUILDING,

};