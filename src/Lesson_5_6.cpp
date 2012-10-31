/*
 * Lesson_5_6.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_5_6.h"

#include "OGLShapes.h"

Lesson_5_6::Lesson_5_6()
: m_spin(0)
{
	// TODO Auto-generated constructor stub
}

Lesson_5_6::~Lesson_5_6() {
	// TODO Auto-generated destructor stub
}

void Lesson_5_6::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,(GLfloat)width/(GLfloat)height,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_5_6::drawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	draw();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	light_moving();
}

void Lesson_5_6::light_moving()
{
	m_spin=(m_spin+1)%360;
}


void Lesson_5_6::draw()
{
	GLfloat position[]={0.0,0.0,1.5,1.0};

	glPushMatrix();
	glTranslatef(0.0,0.0,-5.0);

	glPushMatrix();
	glRotated((GLdouble)m_spin,1.0,0.0,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glTranslated(0.0,0.0,1.5); glDisable(GL_LIGHTING);
	glColor3f(0.0,1.0,1.0);
	OGLShapes::wireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	OGLShapes::solidTorus(0.275,0.85,40,40);

	glPopMatrix();
}
