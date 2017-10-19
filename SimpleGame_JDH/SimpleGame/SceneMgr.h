#pragma once
#include "Renderer.h"
#include "Object.h"
#define MAX_OBJECT__COUNT 50
class SceneMgr
{
private:
	Object*  b[MAX_OBJECT__COUNT];
public:
	SceneMgr();
	~SceneMgr();
public:
	void Update();
	void Render(Renderer* pr);

	void TestColl();
};