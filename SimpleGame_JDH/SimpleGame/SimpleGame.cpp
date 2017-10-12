/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "Object.h"
Renderer *g_Renderer = NULL;
int Count = 0;
Object*  b[100];

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	

	// Renderer Test
	for (int i = 0; i < Count; ++i)
	{
		if (b[i] != NULL)
		{
			b[i]->Render(g_Renderer);
			b[i]->Update();
		}
	}

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	static bool c = false;
	if ((button == GLUT_LEFT_BUTTON))
	{
		if (state == GLUT_DOWN)
			c = true;
		if (state == GLUT_UP)
		{
			if (c)
			{
				if (b[Count] == NULL)
				{
					b[Count++] = new Object(MyVector(x - 250, 250 - y, 0), 10, 1, 1, 1, 1, 1);
				}
				c = false;
			}
		}

	}

	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
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
	for (int i = 0; i < 100; ++i)
		b[i] = NULL;
	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	glutMainLoop();
	delete g_Renderer;
	for (int i = 0; i < Count; ++i)
	{
		if (b[i] != NULL)
			delete b[i];
	}
    return 0;
}

