/*
 * Lesson_1_2.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_1_2.h"

Lesson_1_2::Lesson_1_2() {
	// TODO Auto-generated constructor stub

}

Lesson_1_2::~Lesson_1_2() {
	// TODO Auto-generated destructor stub
}

void Lesson_1_2::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	// Reset The View
	glLoadIdentity();
}

void Lesson_1_2::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_1_2::draw()
{
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
}
