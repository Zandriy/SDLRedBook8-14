/*
 * Lesson_3_8.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_8.h"

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>

Lesson_3_8::Lesson_3_8() {
	// TODO Auto-generated constructor stub
}

Lesson_3_8::~Lesson_3_8() {
	// TODO Auto-generated destructor stub
}

void Lesson_3_8::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0,(GLfloat) width/ (GLfloat) height,1.0,100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_3_8::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

bool Lesson_3_8::sendMessage(int message, int mode, int x, int y)
{
	GLint viewport[4];
	GLdouble mvmatrix[16], projmatrix[16];

	//y – coordinate в OpenGL
	GLint realy;
	//Backed object x, y, z coordinates
	GLdouble wx,wy,wz;

	switch(message) {
	case SDL_BUTTON_LEFT:
		if (mode==SDL_PRESSED) {
			glGetIntegerv(GL_VIEWPORT,viewport);
			glGetDoublev(GL_MODELVIEW_MATRIX,mvmatrix);
			glGetDoublev(GL_PROJECTION_MATRIX,projmatrix);
			//viewport[3] - the pixel height of the window
			realy=viewport[3]-(GLint)y-1;
			printf("Coordinates in the cursor position (%4d,%4d)\n",x,realy);
			gluUnProject((GLdouble)x,(GLdouble)realy,0.0,mvmatrix,projmatrix,viewport,&wx,&wy,&wz);
			printf("Object coordinates when z=0 (%f,%f,%f)\n",wx,wy,wz);
			gluUnProject((GLdouble)x,(GLdouble)realy,1.0,mvmatrix,projmatrix,viewport,&wx,&wy,&wz);
			printf("Object coordinates when z=1 (%f,%f,%f)\n",wx,wy,wz);
		}
		break;
	case SDL_BUTTON_RIGHT:
		if (mode==SDL_PRESSED)
			exit(0);
		break;
	default:
		return false;
		break;
	}

	return true;
}
