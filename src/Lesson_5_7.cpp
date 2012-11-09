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
, m_action(0)
, m_bWire(false)
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
	gluPerspective(40.0,(GLfloat)width/(GLfloat)height,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Lesson_5_7::drawGLScene()
{
	GLfloat mat_specular[] = { 0.2, 0.4, 8.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 }; // 0.0 ... 128.0
	GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
	GLfloat position[]={0.0, 0.0, 0.0, 1.0};

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

	glLightfv(GL_LIGHT3,GL_POSITION,position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT3);

	draw();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT3);
}

void Lesson_5_7::changeCameraPos()
{
	switch (m_action)
	{
	case 0:
		m_ex = 0.0;
		m_ey = 0.0;
		m_ez = 5.0;
		m_upx = 0.0;
		m_upy = 1.0;
		m_upz = 0.0;
		m_action++;
		break;
	case 1:
		m_ex += 0.1;
		if (m_ex > 10.0) m_action++;
		break;
	case 2:
		m_ey += 0.1;
		if (m_ey > 10.0) m_action++;
		break;
	case 3:
		m_bWire = true;
		m_ez -= 0.1;
		if (m_ez < -5.0) m_action++;
		break;
	case 4:
		m_ex -= 0.1;
		if (m_ex <= 0.0) m_action++;
		break;
	case 5:
		m_upx += 0.1;
		if (m_upx >= 1.0) m_action++;
		break;
	case 6:
		m_upy -= 0.1;
		if (m_upy <= 0.0) m_action++;
		break;
	case 7:
		m_upz += 0.1;
		if (m_upz >= 1.0) m_action++;
		break;
	case 8:
		m_bWire = false;
		m_upx = 0.0;
		m_upy = 1.0;
		m_upz = 0.0;
		m_action++;
		break;
	case 9:
		m_ey -= 0.1;
		if (m_ey <= 0.0) m_action++;
		break;
	case 10:
		m_ez += 0.1;
		if (m_ez >= 5.0) m_action = 1;
		break;
	default:
		m_action = 0;
		break;
	}
}


void Lesson_5_7::draw()
{
	changeCameraPos();
	glPushMatrix();
	gluLookAt(m_ex, m_ey, m_ez, 0.0, 0.0, 0.0, m_upx, m_upy, m_upz);

	if (m_bWire)
		OGLShapes::wireTorus(0.275, 0.85, 16, 30);
	else
		OGLShapes::solidTorus(0.275, 0.85, 8, 15);

	glPopMatrix();;
}
