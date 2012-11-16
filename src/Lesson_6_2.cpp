/*
 * Lesson_6_2.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_6_2.h"

#include "OGLShapes.h"

#include <SDL/SDL.h>

#define MAXZ 8.0
#define MINZ -8.0
#define ZINC 0.4

Lesson_6_2::Lesson_6_2()
: m_sphereList(0)
, m_cubeList(0)
, m_solidZ(MAXZ)
, m_transparentZ(MINZ)
, m_stop(true)
{
}

Lesson_6_2::~Lesson_6_2() {
	// TODO Auto-generated destructor stub
}

void Lesson_6_2::reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
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

void Lesson_6_2::drawGLScene()
{
	if ( !m_sphereList )
	{
		m_sphereList = glGenLists(1);
		glNewList(m_sphereList, GL_COMPILE);
		OGLShapes::solidSphere (0.4, 16, 16);
		glEndList();
	}

	if ( !m_cubeList )
	{
		m_cubeList = glGenLists(1);
		glNewList(m_cubeList, GL_COMPILE);
		OGLShapes::solidCube (0.6);
		glEndList();
	}

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.15 };
	GLfloat mat_shininess[] = { 100.0 };
	GLfloat position[] = { 0.5, 0.5, 1.0, 0.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	if (!m_stop)
		animate();

	draw();

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_DEPTH_TEST);
}

void Lesson_6_2::draw()
{
	GLfloat mat_solid[] = { 0.75, 0.75, 0.0, 1.0 };
	GLfloat mat_zero[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_transparent[] = { 0.0, 0.8, 0.8, 0.6 };
	GLfloat mat_emission[] = { 0.0, 0.3, 0.3, 0.6 };

	glPushMatrix ();
	glTranslatef (-0.15, -0.15, m_solidZ);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid);
	glCallList (m_sphereList);
	glPopMatrix ();

	glPushMatrix ();
	glTranslatef (0.15, 0.15, m_transparentZ);
	glRotatef (15.0, 1.0, 1.0, 0.0);
	glRotatef (30.0, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
	glEnable (GL_BLEND);
	glDepthMask (GL_FALSE);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE);
	glCallList (m_cubeList);
	glDepthMask (GL_TRUE);
	glDisable (GL_BLEND);
	glPopMatrix ();
}

void Lesson_6_2::animate()
{
	if (m_solidZ <= MINZ || m_transparentZ >= MAXZ)
		return;
	else
	{
		m_solidZ -= ZINC;
		m_transparentZ += ZINC;
	}
}

bool Lesson_6_2::sendMessage(int message, int mode, int x, int y)
{
	switch (message)
	{
	case SDLK_a:
		m_solidZ = MAXZ;
		m_transparentZ = MINZ;
		m_stop = false;
		break;
	case SDLK_r:
		m_solidZ = MAXZ;
		m_transparentZ = MINZ;
		m_stop = true;
		break;
	default:
		return false;
		break;
	}

	return true;
}
