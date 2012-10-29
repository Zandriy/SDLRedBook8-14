/*
 * Lesson_3_6.cpp
 *
 *  Created on: Oct 7, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_3_6.h"

#include "OGLShapes.h"
#include <SDL/SDL.h>

Lesson_3_6::Lesson_3_6()
:	m_year(0)
,	m_day(0)
{
}

Lesson_3_6::~Lesson_3_6() {
	// TODO Auto-generated destructor stub
}

void Lesson_3_6::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 1.0, 20.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void Lesson_3_6::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();
}

void Lesson_3_6::draw()
{
	glPushMatrix();

	// draw the Sun
	glColor3f (1.0, 0.7, 0.0);
	glRotatef((GLfloat)(m_day/2), 1.0, 0.75, 0.0);
	OGLShapes::wireSphere(1.0, 20, 16);

	glPopMatrix();
	glPushMatrix();

	// draw a planet
	glColor3f (0.0, 0.5, 0.5);
	glRotatef((GLfloat)m_year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)m_day, 0.0, 1.0, 0.0);
	OGLShapes::wireSphere(0.2, 10, 8);

	glPopMatrix();
}

bool Lesson_3_6::sendMessage(int message, int mode, int x, int y)
{
	switch (message) {
	case SDLK_d:
		if (KMOD_NONE == mode)
			m_day = (m_day + 10) % 360;
		else
			m_day = (m_day - 10) % 360;
		drawGLScene();
		break;
		case SDLK_y:
			if (KMOD_NONE == mode)
				m_year = (m_year + 5) % 360;
			else
				m_year = (m_year - 5) % 360;
			drawGLScene();
		break;
		default:
			return false;
		break;
	}

	return true;
}
