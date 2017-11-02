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