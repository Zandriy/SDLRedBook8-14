/*
 * Lesson_1_3.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_1_3.h"

Lesson_1_3::Lesson_1_3()
:	m_spin(0.0)
{
	// TODO Auto-generated constructor stub

}

Lesson_1_3::~Lesson_1_3() {
	// TODO Auto-generated destructor stub
}

void Lesson_1_3::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	// Reset The View
	glLoadIdentity();
}

void Lesson_1_3::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_1_3::draw()
{
	glPushMatrix();

	glRotatef(m_spin, 0.0, 0.0, 1.0);
	glColor3f(0.5, 0.0, 0.5);
	glRectf(-25.0, -25.0, 25.0, 25.0);

	glPopMatrix();

	spinDisplay();
}

void Lesson_1_3::spinDisplay()
{
	m_spin += 0.1;

	if (m_spin > 360.0) m_spin -= 360.0;
}
