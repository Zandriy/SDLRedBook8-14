/*
 * Lesson_5_1.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_5_1.h"

#include "OGLShapes.h"

Lesson_5_1::Lesson_5_1() {
	// TODO Auto-generated constructor stub
}

Lesson_5_1::~Lesson_5_1() {
	// TODO Auto-generated destructor stub
}

void Lesson_5_1::reshape(int width, int height)
{
	   glViewport (0, 0, (GLsizei) width, (GLsizei) height);
	   glMatrixMode (GL_PROJECTION);
	   glLoadIdentity();
	   if (width <= height)
	      glOrtho (-1.5, 1.5, -1.5*(GLfloat)height/(GLfloat)width,
	         1.5*(GLfloat)height/(GLfloat)width, -10.0, 10.0);
	   else
	      glOrtho (-1.5*(GLfloat)width/(GLfloat)height,
	         1.5*(GLfloat)width/(GLfloat)height, -1.5, 1.5, -10.0, 10.0);
	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity();
}

void Lesson_5_1::drawGLScene()
{
	GLfloat mat_specular[] = { 1.0, 0.8, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 }; // 0.0 ... 128.0
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();
	draw();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
}


void Lesson_5_1::draw()
{
	OGLShapes::solidSphere (1.0, 20, 16);
}
