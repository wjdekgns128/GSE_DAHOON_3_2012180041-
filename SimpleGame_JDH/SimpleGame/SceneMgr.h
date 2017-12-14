#pragma once
#include "Renderer.h"
#include "MyDefine.h"
#include "Team.h"
#include "Team1.h"
#include "Team2.h"

#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include "Sound.h"
#include <Windows.h>
class SceneMgr
{
private:
	Sound*		pSound;
	Renderer *SceneRenderer;
	Team*		pTeam[2];
public:
	SceneMgr();
	~SceneMgr();
public:
	void Init();
	void Destory();
public:
	void Update(DWORD ElapsedTime);
	void Render();
	void CollManager();
	BaseObject** getAllObject(int tag);

	void Mouse(int button, int state, int x, int y);
	void Key(int key, int x, int y);
	
private:
	void TextureLoad();
};