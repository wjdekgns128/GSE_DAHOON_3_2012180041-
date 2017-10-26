#pragma once
#include "Renderer.h"
#include "Object.h"
#define MAX_OBJECT__COUNT 50
class SceneMgr
{
private:
	Renderer *g_Renderer;

	Object*  b[MAX_OBJECT__COUNT];
public:
	SceneMgr();
	~SceneMgr();
public:
	void Init();
	void Destory();
public:
	void Update();
	void Render();

	void TestColl();

	bool BoxToBoxColl(float x, float y, float w, float h, float x1, float y1, float w1, float h1);
};