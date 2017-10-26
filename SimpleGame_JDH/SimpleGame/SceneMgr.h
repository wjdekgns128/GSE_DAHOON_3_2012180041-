#pragma once
#include "Renderer.h"
#include "MyDefine.h"
#include "Object.h"
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include <Windows.h>
class SceneMgr
{
private:
	Renderer *SceneRenderer;

	Object*  b[MAX_OBJECT__COUNT];
public:
	SceneMgr();
	~SceneMgr();
public:
	void Init();
	void Destory();
public:
	void Update(DWORD ElapsedTime);
	void Render();

	void TestColl();
	void Mouse(int button, int state, int x, int y);
	bool BoxToBoxColl(float x, float y, float w, float h, float x1, float y1, float w1, float h1);
};