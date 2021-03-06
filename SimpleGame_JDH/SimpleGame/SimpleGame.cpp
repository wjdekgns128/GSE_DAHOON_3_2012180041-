/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
#include <crtdbg.h>
#include   "SceneMgr.h"

//#ifndef _DEBUG
//#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
//#endif


SceneMgr* g_pMgr = NULL;
DWORD timer = timeGetTime();
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	g_pMgr->Render();
	g_pMgr->Update(timeGetTime() - timer);
	timer = timeGetTime();

	// Renderer Test
	glutSwapBuffers();

}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	
	g_pMgr->Mouse(button, state, x, y);
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	g_pMgr->Key(key, x, y);
	RenderScene();
}

int main(int argc, char **argv)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // ��



	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 800);
	glutCreateWindow("Game Software Engineering KPU");
	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}
	if (g_pMgr == NULL)
	{
		g_pMgr = new SceneMgr;
		g_pMgr->Init();
	}

	// Initialize Renderer
	
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	glutMainLoop();
	g_pMgr->Destory();
	delete g_pMgr;

    return 0;
}

