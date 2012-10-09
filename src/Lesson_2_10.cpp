/*
 * Lesson_2_10.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: Andrew Zhabura
 */

#include "Lesson_2_10.h"

Lesson_2_10::Lesson_2_10() {
	// TODO Auto-generated constructor stub
}

Lesson_2_10::~Lesson_2_10() {
	// TODO Auto-generated destructor stub
}

void Lesson_2_10::reshape(int width, int height)
{
	// Setup our viewport.
	glViewport( 0, 0, ( GLint )width, ( GLint )height );

	// change to the projection matrix and set our viewing volume.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// Set coordinate system
	gluOrtho2D(0.0, ( GLdouble )width, 0.0, ( GLdouble )height);

	// Make sure we're changing the model view and not the projection
	glMatrixMode( GL_MODELVIEW );
	// Reset The View
	glLoadIdentity();
}

void Lesson_2_10::drawGLScene()
{
	// Clear The Screen And The Depth Buffer
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	draw();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}

void Lesson_2_10::draw()
{
	GLint vertices[] = {25, 25,
			100, 325,
			175, 25,
			175, 325,
			250, 25,
			325, 325};
	GLfloat colors[] = {1.0, 0.2, 0.2,
			0.2, 0.2, 1.0,
			0.8, 1.0, 0.2,
			0.75, 0.75, 0.75,
			0.35, 0.35, 0.35,
			0.5, 0.5, 0.5};

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(2, GL_INT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glBegin(GL_TRIANGLES);
	glArrayElement(2);
	glArrayElement(3);
	glArrayElement(5);
	glEnd();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}
