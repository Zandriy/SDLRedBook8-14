/*
 * Lesson_3_7.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_7.h"

#include "OGLShapes.h"
#include <SDL/SDL.h>

Lesson_3_7::Lesson_3_7()
:	m_shoulder(0)
,	m_elbow(0)
{
	// TODO Auto-generated constructor stub
}

Lesson_3_7::~Lesson_3_7() {
	// TODO Auto-generated destructor stub
}

void Lesson_3_7::reshape(int width, int height)
{
	glViewport (0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) width/(GLfloat) height, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
}

void Lesson_3_7::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();
}

void Lesson_3_7::draw()
{
	glColor3f(0.5, 0.5, 1.0);

	glPushMatrix();
	glTranslatef (-1.0, 0.0, 0.0);
	glRotatef ((GLfloat) m_shoulder, 0.0, 0.0, 1.0);
	glTranslatef (1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef (2.0, 0.4, 1.0);
	OGLShapes::wireCube (1.0);
	glPopMatrix();

	glTranslatef (1.0, 0.0, 0.0);
	glRotatef ((GLfloat) m_elbow, 0.0, 0.0, 1.0);
	glTranslatef (1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef (2.0, 0.4, 1.0);
	OGLShapes::wireCube (1.0);
	glPopMatrix();

	glPopMatrix();
}

bool Lesson_3_7::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_s:
		if (KMOD_NONE == mode)
			m_shoulder = (m_shoulder + 5) % 360;
		else
			m_shoulder = (m_shoulder - 5) % 360;
		drawGLScene();
		break;
		case SDLK_e:
			if (KMOD_NONE == mode)
				m_elbow = (m_elbow + 5) % 360;
			else
				m_elbow = (m_elbow - 5) % 360;
			drawGLScene();
		break;
		default:
			return false;
		break;
	}

	return true;
}
