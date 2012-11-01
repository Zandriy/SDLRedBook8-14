/*
 * Lesson_5_7.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_5_7.h"

#include "OGLShapes.h"

Lesson_5_7::Lesson_5_7()
: m_ex(0.0)
, m_ey(0.0)
, m_ez(0.0)
, m_upx(0.0)
, m_upy(0.0)
, m_upz(0.0)
{
	// TODO Auto-generated constructor stub
}

Lesson_5_7::~Lesson_5_7() {
	// TODO Auto-generated destructor stub
}

void Lesson_5_7::reshape(int width, int height)
{
	glViewport(0,0,(GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,(GLfloat)width/(GLfloat)height,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_5_7::drawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	GLfloat position[]={0.0,0.0,0.0,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);

	draw();

	//glDisable(GL_LIGHTING);
	//glDisable(GL_LIGHT0);
}


void Lesson_5_7::draw()
{
	glPushMatrix();
	//gluLookAt(m_ex, m_ey, m_ez, 0.0, 0.0, 0.0, m_upx, m_upy, m_upz);
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	OGLShapes::solidTorus(0.275, 0.85, 8, 15);
	glPopMatrix();;
}
