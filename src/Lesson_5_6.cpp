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
, m_rotFact(0.0)
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
	GLfloat mat_specular[] = { 1.0, 0.2, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 }; // 0.0 ... 128.0
	GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	// positional light ( spot )
	glLightfv(GL_LIGHT3,GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT3,GL_SPECULAR, light_specular);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT3);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	draw();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT3);

	light_moving();
}

void Lesson_5_6::light_moving()
{
	m_spin=(m_spin+1)%360;
	m_rotFact += 0.03;
	if (m_rotFact >= 1.0)
		m_rotFact = 0.0;
}


void Lesson_5_6::draw()
{
	GLfloat position[]={0.0,0.0,1.5,1.0};

	glPushMatrix();
	glTranslatef(0.0,0.0,-5.0);

	glPushMatrix();
	glRotated((GLdouble)m_spin,1.0-m_rotFact,0.0,0.0+m_rotFact);
	glLightfv(GL_LIGHT3,GL_POSITION,position);
	glTranslated(0.0,0.0,1.5);
	glRotated((GLdouble)m_spin,0.0,0.0,1.0);
	glDisable(GL_LIGHTING);
	glColor3f(0.0,1.0,1.0);
	OGLShapes::wireSphere(0.1, 0, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	OGLShapes::solidTorus(0.275,0.85,40,40);

	glPopMatrix();
}
