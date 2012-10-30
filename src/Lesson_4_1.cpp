/*
 * Lesson_4_1.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_4_1.h"

Lesson_4_1::Lesson_4_1() {
	// TODO Auto-generated constructor stub
}

Lesson_4_1::~Lesson_4_1() {
	// TODO Auto-generated destructor stub
}

void Lesson_4_1::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width<=height)
		gluOrtho2D(0.0,30.0,0.0,30.0*(GLfloat)height/(GLfloat)width);
	else
		gluOrtho2D(0.0,30.0*(GLfloat)width/(GLfloat)height,0.0,30.0);

	glMatrixMode(GL_MODELVIEW);
}

void Lesson_4_1::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glLoadIdentity();
	draw();
}


void Lesson_4_1::draw()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(5.0,5.0);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(25.0,5.0);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(5.0,25.0);
glEnd();
}
